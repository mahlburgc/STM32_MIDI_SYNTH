/*
 * usart3.c
 *
 *  Created on: Apr 24, 2023
 *      Author: cmahlburg
 */

#include "usart3.h"
#include "stm32f0xx_ll_usart.h"
#include "cmsis_os.h"

extern osMessageQueueId_t uartMidiQueueHandle;

MIDI_UART_RxBuffer_t rxBuffer = { 0 };
uint16_t rxIndex = 0;

typedef struct
{
    const uint8_t* data;
    uint16_t numOfTxBytes;
    uint16_t index;
} TxBuffer_t;

static uint32_t threadFlag_txComplete = (1 << 0);
static osThreadId_t txThread = NULL;
static TxBuffer_t txBuffer = { 0 };
static USART_TypeDef* uartHandle = USART3;

static void MIDI_UART_EnableErrorIT(void);
static void MIDI_UART_DisableErrorIT(void);
static void MIDI_UART_EnableParityErrorIT(void);
static void MIDI_UART_DisableParityErrorIT(void);
static void MIDI_UART_EnableReceiveIT(void);
static void MIDI_UART_DisableReceiveIT(void);
static void MIDI_UART_ISR_ByteReceived(void);
static void MIDI_UART_ISR_SendNextByte(void);

/**
 * @brief Enable all error interrupts (FE, ORE, NF).
 *        Parity error interrupt must be enabled separately.
 */
void MIDI_UART_EnableErrorIT(void)
{
    LL_USART_EnableIT_ERROR(uartHandle);
}

/**
 * @brief Disable all error interrupts (FE, ORE, NF).
 *        Parity error interrupt must be disabled separately.
 */
static void MIDI_UART_DisableErrorIT(void)
{
    LL_USART_DisableIT_ERROR(uartHandle);
}

/**
 * @brief Enable parity error interrupt (PE).
 */
void MIDI_UART_EnableParityErrorIT(void)
{
    LL_USART_EnableIT_PE(uartHandle);
}

/**
 * @brief Disable parity error interrupt (PE).
 */
void MIDI_UART_DisableParityErrorIT(void)
{
    LL_USART_DisableIT_PE(uartHandle);
}

/**
 * @brief Start a single character receive interrupt.
 */
void MIDI_UART_EnableReceiveIT(void)
{
    LL_USART_EnableIT_RXNE(uartHandle);
}

/**
 * @brief Stop a single character receive interrupt.
 */
void MIDI_UART_DisableReceiveIT(void)
{
    LL_USART_DisableIT_RXNE(uartHandle);
}

/**
 * @brief Called from ISR to receive incoming byte and put it to rxBuffer, when receiving uart message.
 */
void MIDI_UART_ISR_ByteReceived(void)
{
    uint8_t rcvByte = LL_USART_ReceiveData8(uartHandle);

    if (rxIndex < MIDI_UART_RX_BUFFER_SIZE)
    {
        rxIndex++;
        rxBuffer.data[rxIndex - 1] = rcvByte;

        if (rxIndex >= 3)
        {
            if(osOK != osMessageQueuePut(uartMidiQueueHandle, &rxBuffer, 0, 0))
            {
                /* TODO error handling */
            }
            rxIndex = 0;
        }
    }
    else
    {
        rxIndex = 0;
    }
}

/**
 * @brief Called from ISR to send next byte from txBuffer, when transmitting uart message.
 */
void MIDI_UART_ISR_SendNextByte(void)
{
    if (txBuffer.numOfTxBytes > 0)
    {
        if (txBuffer.index < (txBuffer.numOfTxBytes - 1))
        {
            txBuffer.index++;

            LL_USART_TransmitData8(uartHandle, txBuffer.data[txBuffer.index]);
        }

        if (txBuffer.index == (txBuffer.numOfTxBytes - 1))
        {
            osThreadFlagsSet(txThread, threadFlag_txComplete);
        }
    }
}

/**
 * @brief Transmit a uart message in interrupt mode.
 *        Therefore the uart transmission is started here and continued within the interrupt callback.
 *        The function is waiting here till the transmission is finished (waiting nonblocking for os flag).
 */
int8_t MIDI_UART_TransmitIT(const uint8_t* data, const uint16_t size, uint32_t timeout)
{
    int8_t status = 0;

    LL_USART_EnableIT_TC(uartHandle);

    txBuffer.data = data;
    txBuffer.numOfTxBytes = size;
    txBuffer.index = 0;
    txThread = osThreadGetId();

    osThreadFlagsClear(threadFlag_txComplete);

    LL_USART_TransmitData8(uartHandle, txBuffer.data[txBuffer.index]);

    /* wait for rest of the message transmission, which is handled in interrupt callback */
    if (0 != (osFlagsError & osThreadFlagsWait(threadFlag_txComplete, osFlagsWaitAll, timeout)))
    {
        status = -1;
    }

    return status;
}

/**
 * @brief The Interrupt Service Routine (ISR) for the gnss uart callback.
 *        The ISR checks for error flags and handle rx and tx process.
 */
void MIDI_UART_ISR(void)
{
    /* check for errors */
    if (0 != (LL_USART_IsActiveFlag_ORE(uartHandle)))
    {
        LL_USART_ClearFlag_ORE(uartHandle);
    }
    if (0 != (LL_USART_IsActiveFlag_FE(uartHandle)))
    {
        LL_USART_ClearFlag_FE(uartHandle);
    }
    if (0 != (LL_USART_IsActiveFlag_PE(uartHandle)))
    {
        LL_USART_ClearFlag_PE(uartHandle);
    }
    if (0 != (LL_USART_IsActiveFlag_NE(uartHandle)))
    {
        LL_USART_ClearFlag_NE(uartHandle);
    }

    /* check for tx process */
    if (0 != (LL_USART_IsActiveFlag_TC(uartHandle)))
    {
        MIDI_UART_ISR_SendNextByte();
        LL_USART_ClearFlag_TC(uartHandle);
    }

    /* check for rx process */
    if (0 != (LL_USART_IsActiveFlag_RXNE(uartHandle)))
    {
        MIDI_UART_ISR_ByteReceived();
    }
}

/**
 * @brief Initialize uart.
 */
void MIDI_UART_Init(void)
{
    MIDI_UART_EnableErrorIT();
    MIDI_UART_EnableReceiveIT();
}


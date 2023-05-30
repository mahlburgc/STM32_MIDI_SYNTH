/*
 * usart3.h
 *
 *  Created on: Apr 24, 2023
 *      Author: cmahlburg
 */

#ifndef USART3_H_
#define USART3_H_

#include "stdint.h"

#define MIDI_UART_RX_BUFFER_SIZE 20

typedef struct
{
    uint8_t data[MIDI_UART_RX_BUFFER_SIZE];
} MIDI_UART_RxBuffer_t;

void MIDI_UART_Init(void);
void MIDI_UART_ISR(void);
int8_t MIDI_UART_TransmitIT(const uint8_t* data, const uint16_t size, uint32_t timeout);

#endif /* USART_H_ */

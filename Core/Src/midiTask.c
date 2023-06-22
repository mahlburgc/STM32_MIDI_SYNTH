/*
 * midiTask.c
 *
 *  Created on: 22.06.2023
 *      Author: cmahlburg
 */

#include "midiTask.h"

#include "songs.h"
#include "usart3.h"
#include "music.h"
#include "cmsis_os.h"
#include "main.h"

#define NR_OF_SPEAKER 3

typedef struct
{
    Speaker_t speaker;
    uint8_t inUse;
    uint8_t activeNoteIndex;
} SpeakerChannel_t;

static SpeakerChannel_t speakerTable[NR_OF_SPEAKER] =
{
    { .speaker = {TIM14, LL_TIM_CHANNEL_CH1 }, .inUse = 0, .activeNoteIndex = 0 },/* PA4 */
    { .speaker = {TIM3, LL_TIM_CHANNEL_CH1 }, .inUse = 0, .activeNoteIndex = 0 },/* PB4 */
    { .speaker = {TIM2, LL_TIM_CHANNEL_CH2 }, .inUse = 0, .activeNoteIndex = 0 },/* PB3 */
};

void parseMidiCmd(MIDI_UART_RxBuffer_t* midiCmdBuffer);
void startFreeChannel(uint8_t noteIndex);
void stopChannelByNote(uint8_t noteIndex);
int8_t getNextFreeSpeakerChannel(void);
int8_t getActiveChannelByNote(uint8_t noteIndex);

static uint32_t midiFrequencyArray[] =
{
      c1   ,
      cis1 ,
      d1   ,
      dis1 ,
      e1   ,
      f1   ,
      fis1 ,
      g1   ,
      gis1 ,
      a1   ,
      ais1 ,
      h1   ,
      c2   ,
      cis2 ,
      d2   ,
      dis2 ,
      e2   ,
      f2   ,
      fis2 ,
      g2   ,
      gis2 ,
      a2   ,
      ais2 ,
      h2   ,
      c3   ,
      cis3 ,
      d3   ,
      dis3 ,
      e3   ,
      f3   ,
      fis3 ,
      g3   ,
      gis3 ,
      a3   ,
      ais3 ,
      h3   ,
      c4   ,
      cis4 ,
      d4   ,
      dis4 ,
      e4   ,
      f4   ,
      fis4 ,
      g4   ,
      gis4 ,
      a4   ,
      ais4 ,
      h4   ,
      c5   ,
      cis5 ,
      d5   ,
      dis5 ,
      e5   ,
      f5   ,
      fis5 ,
      g5   ,
      gis5 ,
      a5   ,
      ais5 ,
      h5   ,
      c6   ,
};

/**
 * @brief Function implementing the uartMidiTask thread.
 * @param argument: Not used
 * @retval None
 */
void StartUartMidiTask(void *argument)
{
  MIDI_UART_RxBuffer_t midiCmdBuffer = { 0 };

  MIDI_UART_Init();

  for(;;)
  {
    if (osOK == osMessageQueueGet(uartMidiQueueHandle, &midiCmdBuffer,NULL, osWaitForever))
    {
        parseMidiCmd(&midiCmdBuffer);
    }
  }
}

/**
 * @brief TODO
 */
void parseMidiCmd(MIDI_UART_RxBuffer_t* midiCmdBuffer)
{
    switch (midiCmdBuffer->data[0])
    {
        case 0x80:
            stopChannelByNote(midiCmdBuffer->data[1]);
            break;

        case 0x90:
            startFreeChannel(midiCmdBuffer->data[1]);
            break;

        default:
            break;
    }
}

/**
 * @brief TODO
 */
void stopChannelByNote(uint8_t noteIndex)
{
    int8_t activeSpeaker = getActiveChannelByNote(noteIndex);

    if ((activeSpeaker >= 0) && (activeSpeaker < NR_OF_SPEAKER))
    {
        MUSIC_Stop(speakerTable[activeSpeaker].speaker);
        speakerTable[activeSpeaker].inUse = 0;
    }
}

/**
 * @brief TODO
 */
void startFreeChannel(uint8_t noteIndex)
{
    int8_t nextFreeSpeaker = getNextFreeSpeakerChannel();

    if ((nextFreeSpeaker >= 0) && (nextFreeSpeaker < NR_OF_SPEAKER))
    {
        if (noteIndex < (sizeof(midiFrequencyArray)/sizeof(midiFrequencyArray[0])))
        {
            speakerTable[nextFreeSpeaker].inUse = 1;
            speakerTable[nextFreeSpeaker].activeNoteIndex = noteIndex;
            MUSIC_PlayCont(speakerTable[nextFreeSpeaker].speaker, midiFrequencyArray[noteIndex]);
        }
    }
}

/**
 * @brief TODO
 */
int8_t getNextFreeSpeakerChannel(void)
{
    int8_t retVal = -1;

    for (int8_t i = 0; i < NR_OF_SPEAKER; i++)
    {
        if (speakerTable[i].inUse == 0)
        {
            retVal = i;
            break;
        }
    }

    return retVal;
}

/**
 * @Brief TODO
 */
int8_t getActiveChannelByNote(uint8_t noteIndex)
{
    int8_t retVal = -1;

    for (int8_t i = 0; i < NR_OF_SPEAKER; i++)
    {
        if ((speakerTable[i].activeNoteIndex == noteIndex) && (speakerTable[i].inUse == 1))
        {
            retVal = i;
            break;
        }
    }

#if 0
    if (retVal == -1)
    {
        return -1;
    }
#endif
    return retVal;
}

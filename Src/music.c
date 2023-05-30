/********************************************************************************
 * @file           : music.c
 * @author         : Christian Mahlburg
 * @date           : 16.11.2022
 * @brief          : Module to play different notes with pwm sound.
 *
 ********************************************************************************
 * MIT License
 *
 * Copyright (c) 2022 CMA
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 ********************************************************************************/

#include "music.h"
#include "speaker.h"
#include "cmsis_os.h"

#define Delay(x) osDelay(x)

#define DEFAULT_BPM 120 /* initial beats per minute */
#define DEDAULT_QUARTER_MS ((60 * 1000) / DEFAULT_BPM) /* initial quarter tone length in ms */

#define STACCATO_OFF_TIME_PERCENT 10 /* staccato note off time duration in percent */
#define NOTE_OFF_TIME_MS 2 /* note off time duration in ms to clearly separate each tone */

/* tone length in ms */
uint32_t full = DEDAULT_QUARTER_MS * 4;
uint32_t half = DEDAULT_QUARTER_MS * 2;
uint32_t quarter = DEDAULT_QUARTER_MS;
uint32_t quarter_triplet = (DEDAULT_QUARTER_MS * 2) / 3;
uint32_t eighth = DEDAULT_QUARTER_MS / 2;
uint32_t eighth_triplet = DEDAULT_QUARTER_MS / 3;
uint32_t sixteenth = DEDAULT_QUARTER_MS / 4;
uint32_t thirtysecond = DEDAULT_QUARTER_MS / 8;

/**
 * @brief Calculate new tone length in ms for given bpm.
 */
void MUSIC_SetBPM(uint32_t bpm)
{
    quarter = (60 * 1000) / bpm;

    full = quarter * 4;
    half = quarter * 2;
    quarter_triplet = half / 3;
    eighth = quarter / 2;
    eighth_triplet = quarter / 3;
    sixteenth = quarter / 4;
    thirtysecond = quarter / 8;
}

/**
 * @brief Start playing a note with a given frequency.
 */
void MUSIC_PlayCont(Speaker_t sp, uint32_t freq_cHz)
{
    SPEAKER_Start(sp, freq_cHz);
}

/**
 * @brief Stop playing a note.
 */
void MUSIC_Stop(Speaker_t sp)
{
    SPEAKER_Stop(sp);
}

/**
 * @brief Play a note with a given frequency and duration.
 */
void MUSIC_Play(Speaker_t sp, uint32_t freq_cHz, uint32_t duration)
{
    SPEAKER_Start(sp, freq_cHz);

    Delay(duration - NOTE_OFF_TIME_MS);

    SPEAKER_Stop(sp);

    Delay(NOTE_OFF_TIME_MS);
}

/**
 * @brief Play two notes with a given frequency and duration.
 */
void MUSIC_PlayTwo(Speaker_t sp1, uint32_t freq1_cHz, Speaker_t sp2, uint32_t freq2_cHz, uint32_t duration)
{
    SPEAKER_Start(sp1, freq1_cHz);
    SPEAKER_Start(sp2, freq2_cHz);

    Delay(duration - NOTE_OFF_TIME_MS);

    SPEAKER_Stop(sp1);
    SPEAKER_Stop(sp2);

    Delay(NOTE_OFF_TIME_MS);
}

/**
 * @brief Play a note with a given frequency and duration.
 *        A staccato is added here.
 */
void MUSIC_PlayStac(Speaker_t sp, uint32_t freq_cHz, uint32_t duration)
{
    uint32_t stacOffTime = (duration * STACCATO_OFF_TIME_PERCENT) / 100;

    SPEAKER_Start(sp, freq_cHz);

    Delay(duration - stacOffTime);

    SPEAKER_Stop(sp);

    Delay(stacOffTime);
}

/**
 * @brief Play two notes with a given frequency and duration.
 *        A staccato is added here.
 */
void MUSIC_PlayTwoStac(Speaker_t sp1, uint32_t freq1_cHz, Speaker_t sp2, uint32_t freq2_cHz, uint32_t duration)
{
    uint32_t stacOffTime = (duration * STACCATO_OFF_TIME_PERCENT) / 100;

    SPEAKER_Start(sp1, freq1_cHz);
    SPEAKER_Start(sp2, freq2_cHz);

    Delay(duration - stacOffTime);

    SPEAKER_Stop(sp1);
    SPEAKER_Stop(sp2);

    Delay(stacOffTime);
}

/**
 * @brief Pause for given duration.
 */
void MUSIC_Pause(uint32_t duration)
{
    Delay(duration);
}


/********************************************************************************
 * @file           : songs.c
 * @author         : Christian Mahlburg
 * @date           : 20.11.2022
 * @brief          : Implementation of different pwm songs.
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

#include "songs.h"
#include "music.h"

/* pwm speaker */
static Speaker_t left = { TIM14, LL_TIM_CHANNEL_CH1 }; /* PA4 */
static Speaker_t middle = { TIM2, LL_TIM_CHANNEL_CH2 }; /* PB3 */
static Speaker_t right = { TIM3, LL_TIM_CHANNEL_CH1 }; /* PB4 */

/**
 * @brief Play ACDC - Thunderstruck
 */
void SONGS_Play_ACDC(void)
{
    MUSIC_SetBPM(134);

    for (uint8_t i = 0; i < 4; i++)
    {
       MUSIC_Play(left, e4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, g4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       MUSIC_Play(left, f4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, gis4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       MUSIC_Play(left, e4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, g4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 4; i++)
    {
       MUSIC_Play(left, f4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, gis4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
    }
    for (uint8_t i = 0; i < 2; i++)
    {
       MUSIC_Play(left, c5, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, ais4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, a4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, ais4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, a4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, g4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, a4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       MUSIC_Play(left, f4, sixteenth);
       MUSIC_Play(left, c4, sixteenth);
       for (uint8_t i = 0; i < 4; i++)
       {
           MUSIC_Play(left, g4, sixteenth);
           MUSIC_Play(left, c4, sixteenth);
           MUSIC_Play(left, e4, sixteenth);
           MUSIC_Play(left, c4, sixteenth);
       }
    }
}

/**
 * @brief Play Super Mario Bros. Theme Song
 */
void SONGS_Play_SuperMario(void)
{
    MUSIC_SetBPM(180);

    MUSIC_Play(left, fret_E12, eighth);
    MUSIC_Play(left, fret_E12, eighth);
    MUSIC_Pause(eighth);
    MUSIC_Play(left, fret_E12, eighth);
    MUSIC_Pause(eighth);
    MUSIC_Play(left, fret_E8, eighth);
    MUSIC_Play(left, fret_E12, quarter);
    MUSIC_Play(left, fret_E15, quarter);
    MUSIC_Pause(quarter);
    MUSIC_Play(left, fret_H8, quarter);
    MUSIC_Pause(quarter);
}

/**
 * @brief Play Tetris Right Piano Hand
 */
void SONGS_Play_Tetris_RightHand(void)
{
    MUSIC_SetBPM(150);

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 1 */
        MUSIC_Play(right, e5, quarter);
        MUSIC_Play(right, h4, eighth);
        MUSIC_Play(right, c5, eighth);
        MUSIC_Play(right, d5, eighth);
        MUSIC_Play(right, e5, sixteenth);
        MUSIC_Play(right, d5, sixteenth);
        MUSIC_Play(right, c5, eighth);
        MUSIC_Play(right, h4, eighth);

        /* 2 */
        MUSIC_Play(right, a4, quarter);
        MUSIC_Play(right, a4, eighth);
        MUSIC_Play(right, c5, eighth);
        MUSIC_Play(right, e5, quarter);
        MUSIC_Play(right, d5, eighth);
        MUSIC_Play(right, c5, eighth);

        /* 3 */
        MUSIC_Play(right, h4, quarter);
        MUSIC_Play(right, h4, eighth);
        MUSIC_Play(right, c5, eighth);
        MUSIC_Play(right, d5, quarter);
        MUSIC_Play(right, e5, quarter);

        /* 4 */
        MUSIC_Play(right, c5, quarter);
        MUSIC_Play(right, a4, quarter);
        MUSIC_Play(right, a4, half);

        /* 5 */
        MUSIC_Play(right, 0, eighth);
        MUSIC_Play(right, d5, quarter);
        MUSIC_Play(right, f5, eighth);
        MUSIC_Play(right, a5, quarter);
        MUSIC_Play(right, g5, eighth);
        MUSIC_Play(right, f5, eighth);

        /* 6 */
        MUSIC_Play(right, 0, eighth);
        MUSIC_Play(right, e5, quarter);
        MUSIC_Play(right, c5, eighth);
        MUSIC_Play(right, e5, quarter);
        MUSIC_Play(right, d5, eighth);
        MUSIC_Play(right, c5, eighth);

        /* 7 */
        MUSIC_Play(right, h4, quarter);
        MUSIC_Play(right, h4, eighth);
        MUSIC_Play(right, c5, eighth);
        MUSIC_Play(right, d5, quarter);
        MUSIC_Play(right, e5, quarter);

        /* 8 */
        MUSIC_Play(right, c5, quarter);
        MUSIC_Play(right, a4, quarter);
        MUSIC_Play(right, a4, half);
    }

    /* 17 */
    MUSIC_PlayTwo(right, e5, middle, c5, half);
    MUSIC_PlayTwo(right, c5, middle, a4, half);

    /* 18 */
    MUSIC_PlayTwo(right, d5, middle, h4, half);
    MUSIC_PlayTwo(right, h4, middle, gis4, half);

    /* 19 */
    MUSIC_PlayTwo(right, c5, middle, a4, half);
    MUSIC_PlayTwo(right, a4, middle, e4, half);

    /* 20 */
    MUSIC_PlayTwo(right, gis4, middle, e4, half);
    MUSIC_PlayTwo(right, h4, middle, gis4, half);

    /* 21 */
    MUSIC_PlayTwo(right, e5, middle, c5, half);
    MUSIC_PlayTwo(right, c5, middle, a4, half);

    /* 22 */
    MUSIC_PlayTwo(right, d5, middle, h4, half);
    MUSIC_PlayTwo(right, h4, middle, gis4, half);

    /* 23 */
    MUSIC_PlayTwo(right, c5, middle, a4, quarter);
    MUSIC_PlayTwo(right, e5, middle, c5, quarter);
    MUSIC_PlayTwo(right, a5, middle, e5, quarter);
    MUSIC_PlayTwo(right, a5, middle, e5, quarter);

    /* 24*/
    MUSIC_PlayTwo(right, gis5, middle, e5, full);

    /*********** third part ********/

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 25 */
        MUSIC_PlayTwo(right, e5, middle, h4, quarter);

        MUSIC_PlayTwo(right, h4, middle, gis4, eighth);
        MUSIC_PlayTwo(right, c5, middle, a4, eighth);

        MUSIC_PlayTwo(right, d5, middle, h4, eighth);
        MUSIC_Play(right, e5, sixteenth);
        MUSIC_Play(right, d5, sixteenth);

        MUSIC_PlayTwo(right, c5, middle, a4, eighth);
        MUSIC_PlayTwo(right, h4, middle, gis4, eighth);

        /* 26 */
        MUSIC_PlayTwo(right, a4, middle, e4, quarter);

        MUSIC_PlayTwo(right, a4, middle, e4, eighth);
        MUSIC_PlayTwo(right, c5, middle, a5, eighth);

        MUSIC_PlayTwo(right, e5, middle, c5, quarter);

        MUSIC_PlayTwo(right, d5, middle, h4, eighth);
        MUSIC_PlayTwo(right, c5, middle, a4, eighth);

        /* 27 */
        MUSIC_PlayTwo(right, h4, middle, gis4, eighth);
        MUSIC_PlayTwo(right, e4, middle, 0, eighth);

        MUSIC_Play(right, gis4, sixteenth);
        MUSIC_Play(right, gis4, sixteenth);
        MUSIC_Play(right, c5, eighth);

        MUSIC_PlayTwo(right, d5, middle, h4, quarter);

        MUSIC_PlayTwo(right, e5, middle, c4, quarter);

        /* 28 */
        MUSIC_PlayTwo(right, c5, middle, a4, quarter);
        MUSIC_PlayTwo(right, a4, middle, e4, quarter);

        MUSIC_PlayTwo(right, a4, middle, e4, half);

        /* 29 */
        MUSIC_Pause(eighth);
        MUSIC_PlayTwo(right, d5, middle, f4, quarter);
        MUSIC_PlayTwo(right, f5, middle, a4, eighth);

        MUSIC_PlayTwo(right, a5, middle, c5, quarter);
        MUSIC_PlayTwo(right, g5, middle, h4, eighth);
        MUSIC_PlayTwo(right, f5, middle, a4, eighth);

        /* 30 */
        MUSIC_Pause(eighth);
        MUSIC_PlayTwo(right, e5, middle, g4, quarter);
        MUSIC_PlayTwo(right, c5, middle, e5, eighth); /* e4 */

        MUSIC_PlayTwo(right, e5, middle, g4, quarter);
        MUSIC_PlayTwo(right, d5, middle, f4, eighth);
        MUSIC_PlayTwo(right, c5, middle, e4, eighth);

        /* 31 */
        MUSIC_PlayTwo(right, h4, middle, gis4, eighth);
        MUSIC_PlayTwo(right, e4, middle, 0, eighth);

        MUSIC_Play(right, gis4, sixteenth);
        MUSIC_Play(right, gis4, sixteenth);
        MUSIC_Play(right, c5, eighth);

        MUSIC_PlayTwo(right, d5, middle, h4, quarter);

        MUSIC_PlayTwo(right, e5, middle, c4, quarter);

        /* 32 */
        MUSIC_PlayTwo(right, c5, middle, a4, quarter);
        MUSIC_PlayTwo(right, a4, middle, e4, quarter);

        MUSIC_PlayTwo(right, a4, middle, e4, half);
    }

    /* end */
}


/**
 * @brief Play Tetris Left Piano Hand
 */
void SONGS_Play_Tetris_LeftHand(void)
{
    MUSIC_SetBPM(150);

    /*********** first part ********/
    /* 1 */
    MUSIC_Pause(full);

    /* 2 */
    MUSIC_Pause(full);

    /* 3 */
    MUSIC_Pause(full);

    /* 4 */
    MUSIC_Pause(full);

    /* 5 */
    MUSIC_Pause(full);

    /* 6 */
    MUSIC_Pause(full);

    /* 7 */
    MUSIC_Pause(full);

    /* 8 */
    MUSIC_Pause(full);

    /* 9 */
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 10 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);

    /* 11 */
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, gis3, eighth);
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, gis3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 12 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, c2, eighth);
    MUSIC_Play(left, d3, eighth);

    /* 13 */
    MUSIC_Play(left, d2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, d2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, d2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, d2, eighth);
    MUSIC_Play(left, d3, eighth);

    /* 14 */
    MUSIC_Play(left, c2, eighth);
    MUSIC_Play(left, c3, eighth);
    MUSIC_Play(left, c2, eighth);
    MUSIC_Play(left, c3, eighth);
    MUSIC_Play(left, c2, eighth);
    MUSIC_Play(left, c3, eighth);
    MUSIC_Play(left, c2, eighth);
    MUSIC_Play(left, c3, eighth);

    /* 15 */
    MUSIC_Play(left, g2, eighth);
    MUSIC_Play(left, g3, eighth);
    MUSIC_Play(left, g2, eighth);
    MUSIC_Play(left, g3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, e2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 16 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, a3, eighth);
    MUSIC_Play(left, a2, quarter);

    /*********** second part ********/

    /* 17 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 18 */
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);

    /* 19 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 20 */
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 21 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 22 */
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);
    MUSIC_Play(left, h2, eighth);
    MUSIC_Play(left, d3, eighth);

    /* 23 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, a2, eighth);
    MUSIC_Play(left, e3, eighth);

    /* 24 */
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, gis2, eighth);
    MUSIC_Play(left, e3, eighth);
    MUSIC_Play(left, gis2, quarter - 10);
    MUSIC_Pause(10);
    MUSIC_Play(left, gis2, quarter - 10);
    MUSIC_Pause(10);

    /*********** third part ********/

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 25 */
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);

        /* 26 */
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);

        /* 27 */
        MUSIC_Play(left, gis2, eighth);
        MUSIC_Play(left, gis3, eighth);
        MUSIC_Play(left, gis2, eighth);
        MUSIC_Play(left, gis3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);

        /* 28 */
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, h2, eighth);
        MUSIC_Play(left, c2, eighth);
        MUSIC_Play(left, d3, eighth);

        /* 29 */
        MUSIC_Play(left, d2, eighth);
        MUSIC_Play(left, d3, eighth);
        MUSIC_Play(left, d2, eighth);
        MUSIC_Play(left, d3, eighth);
        MUSIC_Play(left, d2, eighth);
        MUSIC_Play(left, d3, eighth);
        MUSIC_Play(left, d2, eighth);
        MUSIC_Play(left, d3, eighth);

        /* 30 */
        MUSIC_Play(left, c2, eighth);
        MUSIC_Play(left, c3, eighth);
        MUSIC_Play(left, c2, eighth);
        MUSIC_Play(left, c3, eighth);
        MUSIC_Play(left, c2, eighth);
        MUSIC_Play(left, c3, eighth);
        MUSIC_Play(left, c2, eighth);
        MUSIC_Play(left, c3, eighth);

        /* 31 */
        MUSIC_Play(left, gis2, eighth);
        MUSIC_Play(left, gis3, eighth);
        MUSIC_Play(left, gis2, eighth);
        MUSIC_Play(left, gis3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, e3, eighth);

        /* 32 */
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, eighth);
        MUSIC_Play(left, a3, eighth);
        MUSIC_Play(left, a2, quarter);
    }
    /* end */
}

/**
 * @brief Play Tetris Ragtime Right Piano Hand
 */
void SONGS_Play_TetrisRagtime_RightHand(void)
{
    MUSIC_SetBPM(125);

    /* 1 */
    MUSIC_Pause(full);

    /* 2 */
    MUSIC_Pause(quarter);
    MUSIC_PlayStac(right, h4, eighth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, h4, eighth);

    /* 3 */
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, a4, eighth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, e5, eighth - 25);
    MUSIC_Pause(25);
    MUSIC_PlayStac(right, e5, eighth - 25);
    MUSIC_Pause(25);
    MUSIC_PlayStac(right, d5, eighth);
    MUSIC_PlayStac(right, c5, eighth);

    /* 4 */
    MUSIC_PlayStac(right, h4, quarter + eighth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_PlayStac(right, e5, quarter);

    /* 5 */
    MUSIC_PlayStac(right, c5, quarter);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, a4, half);

    /* 6 */
    MUSIC_Pause(eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_PlayStac(right, f5, eighth);
    MUSIC_PlayStac(right, a5, quarter);
    MUSIC_PlayStac(right, g5, eighth);
    MUSIC_PlayStac(right, f5, eighth);

    /* 7 */
    MUSIC_Pause(eighth);
    MUSIC_PlayStac(right, e5, quarter);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, e5, quarter);
    MUSIC_PlayStac(right, d5, eighth);
    MUSIC_PlayStac(right, c5, eighth);

    /* 8 */
    MUSIC_PlayStac(right, h4, quarter + eighth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_Play(right, e5, quarter - thirtysecond);
    MUSIC_Play(right, d5, thirtysecond);

    /* 9 */
    MUSIC_PlayStac(right, c5, quarter);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_Pause(quarter);

    /*****************************************/

    /* 10 */
    MUSIC_Play(right, dis5, thirtysecond);
    MUSIC_Play(right, e5, quarter - thirtysecond);
    MUSIC_PlayStac(right, h4, eighth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, h4, eighth);

    /* 11 */
    MUSIC_PlayStac(right, a4, quarter - sixteenth);
    MUSIC_Play(right, e4, sixteenth);
    MUSIC_Play(right, a4, sixteenth);
    MUSIC_Play(right, e4, sixteenth);
    MUSIC_Play(right, c5, sixteenth);
    MUSIC_Play(right, e4, sixteenth);
    MUSIC_PlayStac(right, e5, eighth - 25);
    MUSIC_Pause(25);
    MUSIC_PlayStac(right, e5, eighth - 25);
    MUSIC_Pause(25);
    MUSIC_PlayStac(right, d5, eighth);
    MUSIC_PlayStac(right, c5, eighth);

    /* 12 */
    MUSIC_PlayStac(right, h4, quarter + eighth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_PlayStac(right, e5, quarter);

    /* 13 */
    MUSIC_PlayStac(right, c5, quarter);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, a4, half);

    /* 14 */
    MUSIC_Pause(eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_PlayStac(right, f5, eighth);
    MUSIC_PlayStac(right, a5, quarter);
    MUSIC_PlayStac(right, g5, eighth);
    MUSIC_PlayStac(right, f5, eighth);

    /* 15 */
    MUSIC_Pause(eighth);
    MUSIC_PlayStac(right, e5, quarter);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, e5, quarter);
    MUSIC_PlayStac(right, d5, eighth);
    MUSIC_PlayStac(right, c5, eighth);

    /* 16 */
    MUSIC_PlayStac(right, h4, quarter + eighth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, quarter);
    MUSIC_Play(right, e5, quarter - thirtysecond);
    MUSIC_Play(right, d5, thirtysecond);

    /* 17 */
    MUSIC_PlayStac(right, c5, quarter);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, a4, quarter);

    MUSIC_Play(right, e5, sixteenth);
    MUSIC_Pause(sixteenth);
    MUSIC_Play(right, c5, sixteenth);
    MUSIC_Play(right, d5, eighth);

    /************ Solo part *************/
    /* 17 */
    /* eighth for above*/
    MUSIC_Pause(sixteenth);
    MUSIC_Pause(eighth);
    MUSIC_Pause(quarter);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, d5, eighth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_Play(right, dis5, thirtysecond);
    MUSIC_Play(right, e5, thirtysecond + eighth);

    /* 18 */
    /* eighth for above*/
    MUSIC_PlayStac(right, c5, eighth);
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, g4, eighth);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_Play(right, e5, sixteenth);
    MUSIC_Play(right, g5, sixteenth);
    MUSIC_Play(right, a5, eighth);

    /* 19 */
    MUSIC_Play(right, c6, eighth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(right, dis5, sixteenth);
    MUSIC_Play(right, e5, sixteenth);
    MUSIC_Play(right, g5, sixteenth);
    MUSIC_Play(right, a5, sixteenth);
    MUSIC_PlayStac(right, c6, eighth + sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(right, dis5, sixteenth);
    MUSIC_Play(right, e5, sixteenth);
    MUSIC_Play(right, g5, sixteenth);
    MUSIC_Play(right, a5, sixteenth);
    MUSIC_Play(right, g5, sixteenth);

    /* 20 */
    MUSIC_PlayStac(right, c6, eighth);
    MUSIC_PlayStac(right, a5, sixteenth);
    MUSIC_PlayStac(right, g5, sixteenth);
    MUSIC_PlayStac(right, a5, sixteenth);
    MUSIC_PlayStac(right, g5, sixteenth);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);
    MUSIC_PlayStac(right, a5, sixteenth);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, e4, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, a4, sixteenth);

    /* 21 */
    MUSIC_PlayStac(right, g5, sixteenth);
    MUSIC_PlayStac(right, f5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, f4, sixteenth);
    MUSIC_PlayStac(right, cis5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);
    MUSIC_PlayStac(right, f5, sixteenth);
    MUSIC_PlayStac(right, a5, sixteenth);
    MUSIC_PlayStac(right, gis5, sixteenth);
    MUSIC_PlayStac(right, g5, sixteenth);
    MUSIC_PlayStac(right, fis5, sixteenth);
    MUSIC_PlayStac(right, f5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, cis5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);

    /* 22 */
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_Pause(sixteenth);
    MUSIC_PlayStac(right, dis4, sixteenth);
    MUSIC_PlayStac(right, e4, sixteenth);
    MUSIC_PlayStac(right, f4, sixteenth);
    MUSIC_PlayStac(right, e4, sixteenth);
    MUSIC_PlayStac(right, f4, sixteenth);
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, e5, quarter);
    MUSIC_Play(right, c5, eighth);
    MUSIC_Play(right, h4, sixteenth);
    MUSIC_Play(right, a4, sixteenth);

    /* 22 */
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, dis5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, gis4, sixteenth);

    /* 23 */
    MUSIC_PlayStac(right, a4, sixteenth);
    MUSIC_PlayStac(right, c5, sixteenth);
    MUSIC_PlayStac(right, e5, sixteenth);
    MUSIC_PlayStac(right, a5, sixteenth);
    MUSIC_PlayStac(right, f5, sixteenth);
    MUSIC_PlayStac(right, d5, sixteenth);
    MUSIC_PlayStac(right, h4, sixteenth);
    MUSIC_PlayStac(right, gis4, sixteenth);
    MUSIC_PlayStac(right, a4, quarter);
    MUSIC_PlayStac(right, a5, eighth);
    MUSIC_Pause(eighth);
}

/**
 * @brief Play Tetris Ragtime Left Piano Hand
 */
void SONGS_Play_TetrisRagtime_LeftHand(void)
{
    MUSIC_SetBPM(125);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 2 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_Pause(eighth + quarter + half);

    /* 3 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 4 */
    MUSIC_Play(left, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 5 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 6 */
    MUSIC_Play(left, d2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, d2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, g2, eighth);
    MUSIC_Play(left, gis2, eighth);

    /* 7 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, d2, eighth);
    MUSIC_Play(left, dis2, eighth);

    /* 8 */
    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 9 */
    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4,sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_Play(left, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);

    /***************************************************/

    /* 10 */
    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, h1, middle, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 11 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 12 */
    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, h1, middle, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e2, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 13 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 14 */
    MUSIC_PlayTwoStac(left, d1, middle, d2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, d1, middle, d2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, g1, middle, g2, eighth);
    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);

    /* 15 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, d1, middle, d2, eighth);
    MUSIC_PlayTwoStac(left, dis1, middle, dis2, eighth);

    /* 16 */
    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, h1, middle, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 17 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4,sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_Pause(eighth);

    MUSIC_Pause(quarter);

    /************ Solo part *************/

    /* 18 */
    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, h1, middle, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 19 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 20 */
    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, h1, middle, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e2, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 21 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 22 */
    MUSIC_PlayTwoStac(left, d1, middle, d2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, d1, middle, d2, eighth);
    MUSIC_PlayTwoStac(left, f3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, g1, middle, g2, eighth);
    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);

    /* 23 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, e3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, d1, middle, d2, eighth);
    MUSIC_PlayTwoStac(left, dis1, middle, dis2, eighth);

    /* 24 */
    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, h1, middle, h2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, e4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, gis1, middle, gis2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, d4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, gis3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    /* 25 */
    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4,sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, e1, middle, e2, eighth);
    MUSIC_PlayTwoStac(left, a3, middle, c4, sixteenth);
    MUSIC_Pause(sixteenth);

    MUSIC_PlayTwoStac(left, a1, middle, a2, eighth);
    MUSIC_Pause(eighth);

    MUSIC_PlayTwoStac(left, a2, middle, c5, eighth);
    MUSIC_Pause(eighth);
}

/**
 * @brief Play Zelda Overworld Soundtrack Piano Right Hand
 */
void SONGS_Play_Zelda_RightHand(void)
{
    MUSIC_SetBPM(140);

    /* 1 */
    MUSIC_PlayTwo(middle, h3, right, g4, eighth);
    MUSIC_Pause(eighth);
    MUSIC_PlayTwo(middle, h3, right, g4, eighth_triplet);
    MUSIC_Play(right, d4, eighth_triplet);
    MUSIC_Play(right, g4, eighth_triplet);

    MUSIC_PlayTwo(middle, a3, right, f4, eighth);
    MUSIC_Pause(eighth);
    MUSIC_PlayTwo(middle, a3, right, f4, eighth_triplet);
    MUSIC_Play(right, g4, eighth_triplet);
    MUSIC_Play(right, a4, eighth_triplet);

    /* 2 */
    MUSIC_PlayTwo(middle, g3, right, b4, eighth);
    MUSIC_Pause(eighth);
    MUSIC_PlayTwo(middle, g3, right, b4, eighth_triplet);
    MUSIC_Play(right, g4, eighth_triplet);
    MUSIC_Play(right, b4, eighth_triplet);

    MUSIC_PlayTwo(middle, a3, right, a4, eighth);
    MUSIC_Pause(eighth);
    MUSIC_PlayTwo(middle, a3, right, a4, eighth_triplet);
    MUSIC_Play(right, b4, eighth_triplet);
    MUSIC_Play(right, c5, eighth_triplet);

    /* 3 */
    MUSIC_PlayTwo(middle, g4, right, d5, half + quarter);
    MUSIC_PlayTwo(middle, f4, right, c5, eighth_triplet);
    MUSIC_PlayTwo(middle, f4, right, c5, eighth_triplet);
    MUSIC_PlayTwo(middle, f4, right, c5, eighth_triplet);

    /* 4 */
    MUSIC_PlayTwo(middle, g4, right, d5, half + quarter);
    MUSIC_Play(right, c5, eighth_triplet);
    MUSIC_Play(right, b4, eighth_triplet);
    MUSIC_Play(right, a4, eighth_triplet);

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 5 */
        MUSIC_Play(right, g4, quarter);
        MUSIC_Play(right, d4, quarter);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, g4, eighth);
        MUSIC_Play(right, g4, sixteenth);
        MUSIC_Play(right, a4, sixteenth);
        MUSIC_Play(right, h4, sixteenth);
        MUSIC_Play(right, c5, sixteenth);

        /* 6 */
        MUSIC_Play(right, d5, half);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, d5, eighth);
        MUSIC_Play(right, d5, eighth_triplet);
        MUSIC_Play(right, es5, eighth_triplet);
        MUSIC_Play(right, f5, eighth_triplet);

        /* 7 */
        MUSIC_Play(right, g5, half);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, g5, eighth);
        MUSIC_Play(right, g5, eighth_triplet);
        MUSIC_Play(right, f5, eighth_triplet);
        MUSIC_Play(right, es5, eighth_triplet);

        /* 8 */
        MUSIC_Play(right, f5, eighth);
        MUSIC_Pause(sixteenth);
        MUSIC_Play(right, es5, sixteenth);
        MUSIC_Play(right, d5, quarter + eighth);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, d4, eighth_triplet);
        MUSIC_Play(right, es4, eighth_triplet);
        MUSIC_Play(right, d4, eighth_triplet);

        /* 9 */
        MUSIC_Play(right, c4, eighth);
        MUSIC_Play(right, c4, sixteenth);
        MUSIC_Play(right, d4, sixteenth);
        MUSIC_Play(right, es4, quarter + quarter);
        MUSIC_Play(right, d4, eighth);
        MUSIC_Play(right, c4, eighth);

        /* 10 */
        MUSIC_Play(right, b3, eighth);
        MUSIC_Play(right, b3, sixteenth);
        MUSIC_Play(right, c4, sixteenth);
        MUSIC_Play(right, d4, quarter + quarter);
        MUSIC_Play(right, c4, eighth);
        MUSIC_Play(right, b3, eighth);

        /* 11 */
        MUSIC_Play(right, a3, eighth);
        MUSIC_Play(right, a3, sixteenth);
        MUSIC_Play(right, h3, sixteenth);
        MUSIC_Play(right, cis4, quarter + quarter);
        MUSIC_Play(right, e4, quarter);

        /* 12 */
        MUSIC_Play(right, d4, eighth);
        MUSIC_Play(right, d5, sixteenth);
        MUSIC_Play(right, d5, sixteenth);
        MUSIC_Play(right, e5, eighth_triplet);
        MUSIC_Play(right, e5, eighth_triplet);
        MUSIC_Play(right, e5, eighth_triplet);
        MUSIC_Play(right, fis5, quarter);
        MUSIC_Pause(quarter);

        /* 13 */
        MUSIC_Play(right, g4, quarter);
        MUSIC_Play(right, d4, quarter);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, g4, eighth);
        MUSIC_Play(right, g4, sixteenth);
        MUSIC_Play(right, a4, sixteenth);
        MUSIC_Play(right, h4, sixteenth);
        MUSIC_Play(right, c5, sixteenth);

        /* 14 */
        MUSIC_Play(right, d5, half);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, d5, eighth);
        MUSIC_Play(right, d5, eighth_triplet);
        MUSIC_Play(right, es5, eighth_triplet);
        MUSIC_Play(right, f5, eighth_triplet);

        /* 15 */
        MUSIC_Play(right, g5, half);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, g5, eighth);
        MUSIC_Play(right, g5, eighth_triplet);
        MUSIC_Play(right, f5, eighth_triplet);
        MUSIC_Play(right, es5, eighth_triplet);

        /* 16 */
        MUSIC_Play(right, f5, eighth);
        MUSIC_Pause(sixteenth);
        MUSIC_Play(right, es5, sixteenth);
        MUSIC_Play(right, d5, quarter + eighth);
        MUSIC_Pause(eighth);
        MUSIC_Play(right, d4, eighth_triplet);
        MUSIC_Play(right, es4, eighth_triplet);
        MUSIC_Play(right, d4, eighth_triplet);

        /* 17 */
        MUSIC_Play(right, c4, eighth);
        MUSIC_Play(right, c4, sixteenth);
        MUSIC_Play(right, d4, sixteenth);
        MUSIC_Play(right, es4, quarter + quarter);
        MUSIC_Play(right, d5, eighth);
        MUSIC_Play(right, c5, eighth);

        /* 18 */
        MUSIC_Play(right, b4, eighth_triplet);
        MUSIC_Play(right, a4, eighth_triplet);
        MUSIC_Play(right, b4, eighth_triplet);
        MUSIC_Play(right, c5, eighth_triplet);
        MUSIC_Play(right, b4, eighth_triplet);
        MUSIC_Play(right, c5, eighth_triplet);
        MUSIC_Play(right, d5, eighth + sixteenth);
        MUSIC_Play(right, d5, sixteenth);
        MUSIC_Play(right, d5, eighth_triplet);
        MUSIC_Play(right, c5, eighth_triplet);
        MUSIC_Play(right, b4, eighth_triplet);

        /* 19 */
        MUSIC_Play(right, d5, quarter_triplet);
        MUSIC_Play(right, b4, quarter_triplet);
        MUSIC_Play(right, g4, quarter_triplet);
        MUSIC_Play(right, fis4, eighth + sixteenth);
        MUSIC_Play(right, fis4, sixteenth);
        MUSIC_Play(right, fis4, eighth_triplet);
        MUSIC_Play(right, e4, eighth_triplet);
        MUSIC_Play(right, fis4, eighth_triplet);

        /* 20 */
        MUSIC_Play(right, g4, eighth_triplet);
        MUSIC_Play(right, a4, eighth_triplet);
        MUSIC_Play(right, b4, eighth_triplet);
        MUSIC_Play(right, c5, eighth_triplet);
        MUSIC_Play(right, b4, eighth_triplet);
        MUSIC_Play(right, a4, eighth_triplet);
        MUSIC_Play(right, b4, quarter);

        /*************************************/

        MUSIC_PlayTwo(middle, d3, right, d4, eighth_triplet);
        MUSIC_PlayTwo(middle, es3, right, es4, eighth_triplet);
        MUSIC_PlayTwo(middle, f3, right, f4, eighth_triplet);

        /* 21 */
        MUSIC_PlayTwo(middle, g3, right, g4, quarter);
        MUSIC_PlayTwo(middle, d3, right, d4, quarter);
        MUSIC_Pause(eighth);
        MUSIC_PlayTwo(middle, g3, right, g4, eighth);
        MUSIC_PlayTwo(middle, g3, right, g4, sixteenth);
        MUSIC_PlayTwo(middle, a3, right, g4, sixteenth);
        MUSIC_PlayTwo(middle, b3, right, b4, sixteenth);
        MUSIC_PlayTwo(middle, c4, right, c5, sixteenth);

        /* 22 */
        MUSIC_PlayTwoStac(middle, a3, right, a4, eighth + sixteenth);
        MUSIC_PlayTwo(middle, f3, right, f4, sixteenth);
        MUSIC_PlayTwo(middle, c3, right, c4, quarter + eighth);
        MUSIC_PlayTwo(middle, c3, right, d4, sixteenth);
        MUSIC_PlayTwo(middle, d3, right, d4, sixteenth);
        MUSIC_PlayTwo(middle, f3, right, f4, sixteenth);
        MUSIC_PlayTwo(middle, es3, right, es4, sixteenth);
        MUSIC_PlayTwo(middle, d3, right, d4, sixteenth);
        MUSIC_PlayTwo(middle, c3, right, c4, sixteenth);

        /* 23 */
        MUSIC_PlayTwoStac(middle, d3, right, d4, eighth + sixteenth);
        MUSIC_PlayTwo(middle, g2, right, g3, sixteenth);
        MUSIC_PlayTwo(middle, g2, right, g3, quarter + eighth);
        MUSIC_PlayTwo(middle, g2, right, g3, sixteenth);
        MUSIC_PlayTwo(middle, fis2, right, fis3, sixteenth);
        MUSIC_PlayTwo(middle, g2, right, g3, sixteenth);
        MUSIC_PlayTwo(middle, a2, right, a3, sixteenth);
        MUSIC_PlayTwo(middle, b2, right, b3, sixteenth);
        MUSIC_PlayTwo(middle, c3, right, c4, sixteenth);

        /* 24 */
        MUSIC_PlayTwo(middle, d3, right, d4, half + quarter);

        /*************************************/

        MUSIC_PlayTwo(middle, b3, right, d4, eighth_triplet);
        MUSIC_PlayTwo(middle, g3, right, b3, eighth_triplet);
        MUSIC_PlayTwo(middle, b3, right, d4, eighth_triplet);

        /* 25 */
        MUSIC_PlayTwoStac(middle, d4, right, b4, eighth + sixteenth);
        MUSIC_PlayTwo(middle, c4, right, a4, sixteenth);
        MUSIC_PlayTwo(middle, b3, right, g4, quarter + eighth_triplet);

        MUSIC_PlayTwo(middle, g3, right, d4, eighth_triplet);
        MUSIC_PlayTwo(middle, g3, right, d4, eighth_triplet);

        MUSIC_PlayTwo(middle, g3, right, d4, eighth_triplet);
        MUSIC_PlayTwo(middle, d3, right, b3, eighth_triplet);
        MUSIC_PlayTwo(middle, b3, right, g4, eighth_triplet);

        /* 26 */
        MUSIC_PlayTwoStac(middle, c4, right, as4, eighth + sixteenth);
        MUSIC_PlayTwo(middle, d4, right, b4, sixteenth);
        MUSIC_PlayTwo(middle, es4, right, c5, quarter + eighth_triplet);

        MUSIC_PlayTwo(middle, es4, right, c5, eighth_triplet);
        MUSIC_PlayTwo(middle, f4, right, d5, eighth_triplet);

        MUSIC_PlayTwo(middle, g4, right, es5, eighth_triplet);
        MUSIC_PlayTwo(middle, as4, right, f5, eighth_triplet);
        MUSIC_PlayTwo(middle, b4, right, es5, eighth_triplet);

        /* 27 */
        MUSIC_PlayCont(right, d5); /* full */

        MUSIC_Play(middle, a4, quarter); /* MUSIC_Pause(quarter); */
        MUSIC_Play(middle, a4, eighth_triplet);
        MUSIC_Play(middle, a4, eighth_triplet);
        MUSIC_Play(middle, a4, eighth_triplet);
        MUSIC_Play(middle, a4, quarter);
        MUSIC_Play(middle, a4, eighth_triplet);
        MUSIC_Play(middle, a4, eighth_triplet);
        MUSIC_Play(middle, a4, eighth_triplet);

        MUSIC_Stop(right);

        /* 28 */
        MUSIC_Play(middle, a4, eighth);
        MUSIC_Play(middle, d5, sixteenth);
        MUSIC_Play(middle, d5, sixteenth);

        MUSIC_Play(middle, e5, eighth_triplet);
        MUSIC_Play(middle, e5, eighth_triplet);
        MUSIC_Play(middle, e5, eighth_triplet);

        MUSIC_Play(middle, fis5, half);
    }
    MUSIC_PlayTwoStac(middle, h4, right, g5, quarter); /* d5 */
    MUSIC_Pause(quarter + half);
}

/**
 * @brief Play Zelda Overworld Soundtrack Piano Left Hand
 */
void SONGS_Play_Zelda_LeftHand(void)
{
    MUSIC_SetBPM(140);

    /* 1 */
    MUSIC_Play(left, g2, quarter);
    MUSIC_Play(left, g2, eighth_triplet);
    MUSIC_Play(left, g2, eighth_triplet);
    MUSIC_Play(left, g2, eighth_triplet);

    MUSIC_Play(left, f2, quarter);
    MUSIC_Play(left, f2, eighth_triplet);
    MUSIC_Play(left, f2, eighth_triplet);
    MUSIC_Play(left, f2, eighth_triplet);

    /* 2 */
    MUSIC_Play(left, es2, quarter);
    MUSIC_Play(left, es2, eighth_triplet);
    MUSIC_Play(left, es2, eighth_triplet);
    MUSIC_Play(left, es2, eighth_triplet);

    MUSIC_Play(left, f2, quarter);
    MUSIC_Play(left, f2, eighth_triplet);
    MUSIC_Play(left, f2, eighth_triplet);
    MUSIC_Play(left, f2, eighth_triplet);

    /* 3 */
    MUSIC_Play(left, g2, quarter);
    MUSIC_Play(left, g2, eighth_triplet);
    MUSIC_Play(left, g2, eighth_triplet);
    MUSIC_Play(left, g2, eighth_triplet);

    MUSIC_Play(left, g2, quarter);
    MUSIC_Play(left, f2, eighth_triplet);
    MUSIC_Play(left, f2, eighth_triplet);
    MUSIC_Play(left, f2, eighth_triplet);

    /* 4 */
    MUSIC_Play(left, g2, quarter);
    MUSIC_Play(left, g2, eighth_triplet);
    MUSIC_Play(left, g2, eighth_triplet);
    MUSIC_Play(left, g2, eighth_triplet);

    MUSIC_Play(left, g2, quarter);
    MUSIC_Play(left, c4, eighth_triplet);
    MUSIC_Play(left, b3, eighth_triplet);
    MUSIC_Play(left, a3, eighth_triplet);

    for (uint8_t i = 0; i < 2; i++)
    {
        /* 5 */
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);

        /* 6 */
        MUSIC_PlayTwoStac(left, f2, middle, c3, quarter);
        MUSIC_PlayTwoStac(left, f2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, f2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, b3, eighth_triplet);
        MUSIC_PlayTwoStac(left, f2, middle, c3, quarter);
        MUSIC_PlayTwoStac(left, f2, middle, c3, quarter);

        /* 7 */
        MUSIC_PlayTwoStac(left, es2, middle, b3, quarter);
        MUSIC_PlayTwoStac(left, es2, middle, b3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, b3, eighth_triplet);
        MUSIC_PlayTwoStac(left, d2, middle, a3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, b3, quarter);
        MUSIC_PlayTwoStac(left, es2, middle, b3, quarter);

        /* 8 */
        MUSIC_PlayTwoStac(left, b2, middle, f3, quarter);
        MUSIC_PlayTwoStac(left, b2, middle, f3, eighth_triplet);
        MUSIC_PlayTwoStac(left, b2, middle, f3, eighth_triplet);
        MUSIC_PlayTwoStac(left, as2, middle, es3, eighth_triplet);
        MUSIC_PlayTwoStac(left, b2, middle, f3, quarter);
        MUSIC_PlayTwoStac(left, b2, middle, f3, quarter);

        /* 9 */
        MUSIC_PlayTwoStac(left, as2, middle, es3, quarter);
        MUSIC_PlayTwoStac(left, as2, middle, es3, eighth_triplet);
        MUSIC_PlayTwoStac(left, as2, middle, es3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, as2, middle, es3, quarter);
        MUSIC_PlayTwoStac(left, as2, middle, es3, quarter);

        /* 10 */
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);

        /* 11 */
        MUSIC_PlayTwoStac(left, a2, middle, e3, quarter);
        MUSIC_PlayTwoStac(left, a2, middle, e3, eighth_triplet);
        MUSIC_PlayTwoStac(left, a2, middle, e3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, a2, middle, e3, quarter);
        MUSIC_PlayTwoStac(left, a2, middle, e3, quarter);

        /* 12 */
        MUSIC_PlayTwo(left, d2, middle, a2, quarter);
        MUSIC_Pause(quarter);
        MUSIC_Pause(quarter);
        MUSIC_Play(left, e2, eighth);
        MUSIC_Play(left, fis2, eighth);

        /* 13 */
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);
        MUSIC_PlayTwoStac(left, g2, middle, d3, quarter);

        /* 14 */
        MUSIC_PlayTwoStac(left, f2, middle, c3, quarter);
        MUSIC_PlayTwoStac(left, f2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, f2, middle, c3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, b3, eighth_triplet);
        MUSIC_PlayTwoStac(left, f2, middle, c3, quarter);
        MUSIC_PlayTwoStac(left, f2, middle, c3, quarter);

        /* 15 */
        MUSIC_PlayTwoStac(left, es2, middle, b3, quarter);
        MUSIC_PlayTwoStac(left, es2, middle, b3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, b3, eighth_triplet);
        MUSIC_PlayTwoStac(left, d2, middle, a3, eighth_triplet);
        MUSIC_PlayTwoStac(left, es2, middle, b3, quarter);
        MUSIC_PlayTwoStac(left, es2, middle, b3, quarter);

        /* 16 */
        MUSIC_PlayTwoStac(left, b2, middle, f3, quarter);
        MUSIC_PlayTwoStac(left, b2, middle, f3, eighth_triplet);
        MUSIC_PlayTwoStac(left, b2, middle, f3, eighth_triplet);
        MUSIC_PlayTwoStac(left, as2, middle, es3, eighth_triplet);
        MUSIC_PlayTwoStac(left, b2, middle, f3, quarter);
        MUSIC_PlayTwoStac(left, b2, middle, f3, quarter);

        /* 17 */
        MUSIC_PlayTwoStac(left, as2, middle, es3, quarter);
        MUSIC_PlayTwoStac(left, as2, middle, es3, eighth_triplet);
        MUSIC_PlayTwoStac(left, as2, middle, es3, eighth_triplet);
        MUSIC_PlayTwoStac(left, g2, middle, d3, eighth_triplet);
        MUSIC_PlayTwoStac(left, as2, middle, es3, quarter);
        MUSIC_PlayTwoStac(left, as2, middle, es3, quarter);

        /* 18 */
        MUSIC_PlayTwo(left, g2, middle, d3, quarter);
        MUSIC_PlayTwo(left, f2, middle, c3, quarter);
        MUSIC_PlayTwo(left, e2, middle, h2, half);

        /* 19 */
        MUSIC_PlayTwo(left, es2, middle, b2, half);
        MUSIC_PlayTwo(left, d2, middle, a2, half);

        /* 20 */
        MUSIC_PlayTwo(left, g2, middle, d3, quarter);
        MUSIC_PlayTwo(left, fis2, middle, c3, quarter);
        MUSIC_PlayTwo(left, g2, middle, d3, half);

        /*************************************/

        /* 21 */
        MUSIC_PlayStac(left, es2, quarter);
        MUSIC_PlayStac(left, es2, eighth_triplet);
        MUSIC_PlayStac(left, es2, eighth_triplet);
        MUSIC_PlayStac(left, es2, eighth_triplet);
        MUSIC_PlayStac(left, es2, quarter);
        MUSIC_PlayStac(left, es2, quarter);

        /* 22 */
        MUSIC_PlayStac(left, d2, quarter);
        MUSIC_PlayStac(left, d2, eighth_triplet);
        MUSIC_PlayStac(left, d2, eighth_triplet);
        MUSIC_PlayStac(left, d2, eighth_triplet);
        MUSIC_PlayStac(left, d2, quarter);
        MUSIC_PlayStac(left, d2, quarter);

        /* 23 */
        MUSIC_PlayStac(left, g2, quarter);
        MUSIC_PlayStac(left, g2, eighth_triplet);
        MUSIC_PlayStac(left, g2, eighth_triplet);
        MUSIC_PlayStac(left, g2, eighth_triplet);
        MUSIC_PlayStac(left, g2, quarter);
        MUSIC_PlayStac(left, g2, quarter);

        /* 24 */
        MUSIC_PlayStac(left, g2, quarter);
        MUSIC_PlayStac(left, g2, quarter);

        /*************************************/

        MUSIC_PlayStac(left, f2, quarter_triplet);
        MUSIC_PlayStac(left, g2, quarter_triplet);
        MUSIC_PlayStac(left, f2, quarter_triplet);

        /* 25 */
        MUSIC_Play(left, es2,  quarter); /* middle, b2, */
        MUSIC_Play(left, es2,  quarter); /* middle, b2, */
        MUSIC_Play(left, es2,  quarter); /* middle, b2, */
        MUSIC_Play(left, es2,  quarter); /* middle, b2, */

        /* 26 */
        MUSIC_Play(left, as2,  quarter); /* middle, es2, */
        MUSIC_Play(left, as2,  quarter); /* middle, es2, */
        MUSIC_Play(left, as2,  quarter); /* middle, es2, */
        MUSIC_Play(left, as2,  quarter); /* middle, es2, */

        /* 27 */
        MUSIC_Play(left, d2,  full); /* middle, a2, */

        /* 28 */
        MUSIC_Pause(half);

        MUSIC_PlayStac(left, d3, eighth_triplet);
        MUSIC_PlayStac(left, es3, eighth_triplet);
        MUSIC_PlayStac(left, d3, eighth_triplet);
        MUSIC_PlayStac(left, c3, eighth_triplet);
        MUSIC_PlayStac(left, b3, eighth_triplet);
        MUSIC_PlayStac(left, a3, eighth_triplet);
    }
    MUSIC_PlayStac(left, g2, quarter); /* d2 or g5 */
    MUSIC_Pause(quarter + half);
}

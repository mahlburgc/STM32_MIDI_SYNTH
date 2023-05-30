/********************************************************************************
 * @file           : music.h
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


#ifndef MUSIC_H_
#define MUSIC_H_

#include "speaker.h"

/* tone interval */
#define MINOR_SECOND    16/15
#define MAJOR_SECOND    9/8
#define MINOR_THIRD     6/5
#define MAJOR_THIRD     5/4
#define PERFECT_FOURT   4/3
#define TRITONE         45/32
#define PERFECT_FIFTH   3/2
#define MINOR_SIXTH     8/5
#define MAJOR_SIXTH     5/3
#define MINOR_SEVENTH   16/9
#define MAJOR_SEVENTH   15/8
#define PERFECT_OCTAVE  2

/* tone frequencies in centiHz*/
#define c1   (uint32_t)(3270) /* 32.70 */
#define cis1 (uint32_t)(3465) /* 34.65 */
#define des1 cis1
#define d1   (uint32_t)(3671) /* 36.71 */
#define dis1 (uint32_t)(3889) /* 38.89 */
#define es1 dis1
#define e1   (uint32_t)(4120) /* 41.20 */
#define f1   (uint32_t)(4365) /* 43.65 */
#define fis1 (uint32_t)(4625) /* 46.25 */
#define ges1 fis1
#define g1   (uint32_t)(4900) /* 49.00 */
#define gis1 (uint32_t)(5191) /* 51.91 */
#define as1 gis1
#define a1   (uint32_t)(5500) /* 55.00 */
#define ais1 (uint32_t)(5827) /* 58.27 */
#define b1 ais1
#define h1   (uint32_t)(6174) /* 61.74 */

#define c2   (uint32_t)(6541) /* 65.41 */
#define cis2 (uint32_t)(6930) /* 69.30 */
#define des2 cis2
#define d2   (uint32_t)(7342) /* 73.42 */
#define dis2 (uint32_t)(7778) /* 77.78 */
#define es2 dis2
#define e2   (uint32_t)(8241) /* 82.41 */
#define f2   (uint32_t)(8731) /* 87.31 */
#define fis2 (uint32_t)(9250) /* 92.50 */
#define ges2 fis2
#define g2   (uint32_t)(9800) /* 98.00 */
#define gis2 (uint32_t)(10383) /* 103.83 */
#define as2 gis2
#define a2   (uint32_t)(11000) /* 110.00 */
#define ais2 (uint32_t)(11654) /* 116.54 */
#define b2 ais2
#define h2   (uint32_t)(12347) /* 123.47 */

#define c3   (uint32_t)(13081) /* 130.81 */
#define cis3 (uint32_t)(13859) /* 138.59 */
#define des3 cis3
#define d3   (uint32_t)(14683) /* 146.83 */
#define dis3 (uint32_t)(15556) /* 155.56 */
#define es3 dis3
#define e3   (uint32_t)(16481) /* 164.81 */
#define f3   (uint32_t)(17461) /* 174.61 */
#define fis3 (uint32_t)(18500) /* 185.00 */
#define ges3 fis3
#define g3   (uint32_t)(19600) /* 196.00 */
#define gis3 (uint32_t)(20765) /* 207.65 */
#define as3 gis3
#define a3   (uint32_t)(22000) /* 220.00 */
#define ais3 (uint32_t)(23308) /* 233.08 */
#define b3 ais3
#define h3   (uint32_t)(24694) /* 246.94 */

#define c4   (uint32_t)(26163) /* 261.63 */
#define cis4 (uint32_t)(27718) /* 277.18 */
#define des4 cis4
#define d4   (uint32_t)(29366) /* 293.66 */
#define dis4 (uint32_t)(31113) /* 329.63 */
#define es4 dis4
#define e4   (uint32_t)(32963) /* 329.63 */
#define f4   (uint32_t)(34923) /* 349.23 */
#define fis4 (uint32_t)(36999) /* 369.99 */
#define ges4 fis4
#define g4   (uint32_t)(39200) /* 392.00 */
#define gis4 (uint32_t)(41530) /* 415.30 */
#define as4 gis4
#define a4   (uint32_t)(44000) /* 440.00 */
#define ais4 (uint32_t)(46616) /* 466.16 */
#define b4 ais4
#define h4   (uint32_t)(49388) /* 493.88 */

#define c5   (uint32_t)(52325) /* 523.25 */
#define cis5 (uint32_t)(55437) /* 554.37 */
#define des5 cis5
#define d5   (uint32_t)(58733) /* 587.33 */
#define dis5 (uint32_t)(62225) /* 622.25 */
#define es5 dis5
#define e5   (uint32_t)(65925) /* 659.25 */
#define f5   (uint32_t)(69846) /* 698.46 */
#define fis5 (uint32_t)(73999) /* 739.99 */
#define ges5 fis5
#define g5   (uint32_t)(78399) /* 783.99 */
#define gis5 (uint32_t)(83061) /* 830.61 */
#define as5 gis5
#define a5   (uint32_t)(88000) /* 880.00 */
#define ais5 (uint32_t)(93233) /* 932.33 */
#define b5 ais5
#define h5   (uint32_t)(98777) /* 987.77 */

#define c6   (uint32_t)(104650) /* 1046.50 */

/* tones on guitar frets */
#define fret_H0 h3
#define fret_H1 c4
#define fret_H2 cis4
#define fret_H3 d4
#define fret_H4 dis4
#define fret_H5 e4
#define fret_H6 f4
#define fret_H7 fis4
#define fret_H8 g4
#define fret_H9 gis4
#define fret_H10 a4
#define fret_H11 ais4
#define fret_H12 h4
#define fret_H13 c5
#define fret_H14 cis5
#define fret_H15 d5

#define fret_E0 e4
#define fret_E1 f4
#define fret_E2 fis4
#define fret_E3 g4
#define fret_E4 gis4
#define fret_E5 a4
#define fret_E6 ais4
#define fret_E7 h4
#define fret_E8 c5
#define fret_E9 cis5
#define fret_E10 d5
#define fret_E11 dis5
#define fret_E12 e5
#define fret_E13 f5
#define fret_E14 fis5
#define fret_E15 g5

/* tone length, should only be manipulated through MUSIC_SetBPM() */
extern uint32_t full;
extern uint32_t half;
extern uint32_t quarter;
extern uint32_t quarter_triplet;
extern uint32_t eighth;
extern uint32_t eighth_triplet;
extern uint32_t sixteenth;
extern uint32_t thirtysecond;

void MUSIC_SetBPM(uint32_t quarterLengthMs);

void MUSIC_PlayCont(Speaker_t sp, uint32_t freq_cHz);
void MUSIC_Stop(Speaker_t sp);
void MUSIC_Pause(uint32_t duration);
void MUSIC_Play(Speaker_t sp, uint32_t freq_cHz, uint32_t duration);
void MUSIC_PlayTwo(Speaker_t sp1, uint32_t freq1_cHz, Speaker_t sp2, uint32_t freq2_cHz, uint32_t duration);
void MUSIC_PlayStac(Speaker_t nr, uint32_t freq_cHz, uint32_t duration);
void MUSIC_PlayTwoStac(Speaker_t sp1, uint32_t freq1_cHz, Speaker_t sp2, uint32_t freq2_cHz, uint32_t duration);

#endif /* MUSIC_H_ */

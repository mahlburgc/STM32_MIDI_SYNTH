/********************************************************************************
 * @file           : speaker.h
 * @author         : Christian Mahlburg
 * @date           : 16.11.2022
 * @brief          : Module to control various speaker with pwm.
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


#ifndef SPEAKER_H_
#define SPEAKER_H_

#include "stdint.h"
#include "stm32f0xx_ll_tim.h"

/**
 * @brief Speaker definition with timer and CC-Channel.
 */
typedef struct
{
    TIM_TypeDef* timer;
    uint32_t channel;
} Speaker_t;

void SPEAKER_Start(Speaker_t sp, uint32_t freq_cHz);
void SPEAKER_Stop(Speaker_t sp);

#endif /* SPEAKER_H_ */

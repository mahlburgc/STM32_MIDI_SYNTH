/********************************************************************************
 * @file           : speaker.c
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

#include "speaker.h"
#include "stm32_assert.h"

static void SPEAKER_SetFrequency(Speaker_t sp, uint32_t freq_cHz);

/**
 * @brief Configure PWM output to given frequency in centiHz by setting ARR Register.
 *        f_pwm = (f_sys)/((arr + 1) * (psc + 1)
 */
static void SPEAKER_SetFrequency(Speaker_t sp, uint32_t freq_cHz)
{
    uint64_t f_sys = (uint64_t)SystemCoreClock * 100; /* in cHz */
    uint32_t f_pwm = freq_cHz;
    uint32_t psc = LL_TIM_GetPrescaler(sp.timer); /* prescaler */

#ifdef DEBUG /* to avoid "unused warning" in release build */
    uint32_t arr_max = 0xFFFF; /* only 16bit values are allowed */
    uint32_t arr_min = 0x0000; /* only 16bit values are allowed */
    uint32_t f_pwm_max = (f_sys / ((arr_min + 1) * (psc + 1)));
    uint32_t f_pwm_min = (f_sys / ((arr_max + 1) * (psc + 1)));

    assert_param((freq_cHz >= f_pwm_min) && (freq_cHz <= f_pwm_max));
#endif

    uint32_t autoReload = (f_sys / (f_pwm * (psc + 1))) - 1;
    uint32_t pulseWidth = ((autoReload + 1) / 2) - 1;

    LL_TIM_SetAutoReload(sp.timer, autoReload);

    if (sp.channel == LL_TIM_CHANNEL_CH1)
    {
      LL_TIM_OC_SetCompareCH1(sp.timer, pulseWidth);
    }
    else if (sp.channel == LL_TIM_CHANNEL_CH2)
    {
      LL_TIM_OC_SetCompareCH2(sp.timer, pulseWidth);
    }
    else if (sp.channel == LL_TIM_CHANNEL_CH3)
    {
      LL_TIM_OC_SetCompareCH3(sp.timer, pulseWidth);
    }
    else if (sp.channel == LL_TIM_CHANNEL_CH4)
    {
      LL_TIM_OC_SetCompareCH4(sp.timer, pulseWidth);
    }
}

/**
 * @brief Start a tone with a given frequency in centiHz.
 *        This is done by configuring and enable PWM output.
 */
void SPEAKER_Start(Speaker_t sp, uint32_t freq_cHz)
{
    LL_TIM_CC_DisableChannel(sp.timer, sp.channel);
    LL_TIM_DisableCounter(sp.timer);

    if (freq_cHz > 0)
    {
        LL_TIM_SetCounter(sp.timer, 0);
        SPEAKER_SetFrequency(sp, freq_cHz);
        LL_TIM_EnableCounter(sp.timer);
        LL_TIM_CC_EnableChannel(sp.timer, sp.channel);
    }
}

/**
 * @brief Stops audio output of given speaker.
 */
void SPEAKER_Stop(Speaker_t sp)
{
    LL_TIM_CC_DisableChannel(sp.timer, sp.channel);
    LL_TIM_DisableCounter(sp.timer);
}

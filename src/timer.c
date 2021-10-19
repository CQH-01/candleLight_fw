/*

The MIT License (MIT)

Copyright (c) 2016 Hubert Denkmair

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/

#include "timer.h"
#include "stm32f0xx_hal.h"

void timer_init()
{
	__HAL_RCC_TIM2_CLK_ENABLE();

	TIM2->CR1 = 0;
	TIM2->CR2 = 0;
	TIM2->SMCR = 0;
	TIM2->DIER = 0;
	TIM2->CCMR1 = 0;
	TIM2->CCMR2 = 0;
	TIM2->CCER = 0;
	TIM2->PSC = 48-1; // run @48MHz/480 = 1MHz = 1us
	TIM2->ARR = 0xFFFFFFFF;
	TIM2->CR1 |= TIM_CR1_CEN;
	TIM2->EGR = TIM_EGR_UG;

	// __HAL_RCC_TIM3_CLK_ENABLE();
    // TIM3->CNT = 0;
    // TIM3->PSC = 48-1;  			//预分频值 （8400）
    // TIM3->ARR = 5-1;  			//重装载值 （1s钟定时）
    // TIM3->CR1 = 0;      		//将控制寄存器1清空
    // TIM3->CR1 |= 1<<2;    		//设置事件更新请求源
    // TIM3->CR1 &= ~(1<<7);   	/*设置无缓冲功能*/
    // TIM3->CR1 &= ~(1<<3);   	/*设置循环模式*/
    // TIM3->DIER |= 1<<0;     	/*允许更新中断使能*/
    // NVIC_EnableIRQ(TIM3_IRQn);  /*使能基本定时器中断*/
    // TIM3->CR1 |= 1<<0;     		/*开启计数器使能*/
}

uint32_t timer_get()
{
	return TIM2->CNT;
}

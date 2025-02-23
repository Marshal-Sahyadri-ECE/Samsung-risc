#include <ch32v00x.h>

#define LED_PIN  GPIO_Pin_0  // Change to the correct PWM pin

void PWM_Init() {
    // Enable clock for GPIOC and Timer (TIM2 or TIM3)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);  // Use TIM2 for PWM

    // Configure PC0 as Alternate Function (PWM output)
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = LED_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;  // Alternate function push-pull
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    // Configure Timer2 for PWM mode
    TIM_TimeBaseInitTypeDef TIM_BaseStruct;
    TIM_BaseStruct.TIM_Period = 1000 - 1;  // PWM Frequency
    TIM_BaseStruct.TIM_Prescaler = 72 - 1; // Clock scaling
    TIM_BaseStruct.TIM_ClockDivision = 0;
    TIM_BaseStruct.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInit(TIM2, &TIM_BaseStruct);

    // Configure PWM mode on TIM2 Channel 1
    TIM_OCInitTypeDef TIM_OCStruct;
    TIM_OCStruct.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCStruct.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCStruct.TIM_Pulse = 500;  // Initial brightness (50% duty cycle)
    TIM_OCStruct.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OC1Init(TIM2, &TIM_OCStruct);

    TIM_OC1PreloadConfig(TIM2, TIM_OCPreload_Enable);

    // Enable Timer
    TIM_Cmd(TIM2, ENABLE);
}

void set_brightness(uint16_t duty) {
    TIM_SetCompare1(TIM2, duty);  // Adjust brightness (0 - 1000)
}

int main() {
    PWM_Init();

    while (1) {
        for (int i = 0; i <= 1000; i += 50) {
            set_brightness(i);  // Increase brightness
            for (volatile int j = 0; j < 100000; j++);  // Small delay
        }

        for (int i = 1000; i >= 0; i -= 50) {
            set_brightness(i);  // Decrease brightness
            for (volatile int j = 0; j < 100000; j++);  // Small delay
        }
    }
}

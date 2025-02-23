A Morse Code Blinker 
Step 1: Understanding Morse Code
Each letter in Morse code is represented by:

Short blink (.) – 1 unit of time
Long blink (-) – 3 units of time
Pause between parts of the letter – 1 unit
Pause between letters – 3 units
Pause between words – 7 units
Example: "SOS" → "... --- ..."

S: Short (.), Short (.), Short (.)
O: Long (-), Long (-), Long (-)
S: Short (.), Short (.), Short (.)
Step 2: Connect the LED
Use the onboard user LED (already available).
If using an external LED, connect it to a GPIO pin with a current-limiting resistor (330Ω).
Step 3: Write the Code
Here’s a simple C program to blink Morse code for "SOS":

c
Copy
Edit
#include <ch32v00x.h>
#include <stdint.h>

#define LED_PIN  GPIO_Pin_0  // Change this to the correct user LED pin

void delay(uint32_t ms) {
    for (uint32_t i = 0; i < ms * 800; i++) {
        __NOP();  // No operation (wastes time)
    }
}

void blink_dot() {
    GPIO_WriteBit(GPIOC, LED_PIN, Bit_SET); // Turn LED ON
    delay(200); // Short blink
    GPIO_WriteBit(GPIOC, LED_PIN, Bit_RESET); // Turn LED OFF
    delay(200); // Short pause
}

void blink_dash() {
    GPIO_WriteBit(GPIOC, LED_PIN, Bit_SET);
    delay(600); // Long blink
    GPIO_WriteBit(GPIOC, LED_PIN, Bit_RESET);
    delay(200); // Short pause
}

void blink_SOS() {
    // "S" - Short, Short, Short
    blink_dot(); blink_dot(); blink_dot();
    delay(400); // Space between letters

    // "O" - Long, Long, Long
    blink_dash(); blink_dash(); blink_dash();
    delay(400);

    // "S" - Short, Short, Short
    blink_dot(); blink_dot(); blink_dot();
    delay(1000); // Longer pause between words
}

int main() {
    // Enable GPIOC clock (Change based on your board)
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    // Configure LED pin as output
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = LED_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);

    while (1) {
        blink_SOS();  // Blink "SOS" continuously
    }
}

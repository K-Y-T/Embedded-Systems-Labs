/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


// Smallest blinking rate (LED2) in milliseconds
#define BLINKING_RATE     500ms


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led1(LED1), led2(LED2), led3(LED3);
    led1 = 0; led2 = 0; led3 = 0;

    while (true) {
        // Change state of LED2 unconditionally as it is the fastest
        led2 = !led2;
        // Change state of LED1 only when LED2 is high
        if (led2 == 1){
            led1 = !led1;
        }
        // Change state of LED3 only when both LED1 and LED2 are high
        if (led1 == 1){
            if (led2 == 1){
                led3 = !led3;
            }
        }
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

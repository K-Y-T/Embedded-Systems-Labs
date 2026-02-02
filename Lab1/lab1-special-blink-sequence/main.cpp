/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <array>


// Blinking rate in milliseconds
#define BLINKING_RATE     200ms

void blinkSequence (std::array<DigitalOut, 3>& arr) {

    // Force all leds to start at off state
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = 0;
    }

    // Leds blink on for 200ms and off for 200ms 5 times each
    for (int i = 0; i < 5; i++){
        // On state
        for (int j = 0; j < 3; j++){
            arr[j] =  !arr[j];
        }
        ThisThread::sleep_for(BLINKING_RATE);
        // Off state
        for (int j = 0; j < 3; j++){
            arr[j] =  !arr[j];
        }
        ThisThread::sleep_for(BLINKING_RATE);
    }
}

int main()
{
    // Create an array of size 3 of the DigitalOut class with the three led objects initialized within
    std::array<DigitalOut, 3> ledlist = {
        DigitalOut(LED1), 
        DigitalOut(LED2), 
        DigitalOut(LED3)
    };

        blinkSequence(ledlist);

        // Go into infinite loop as soon as 5 blinks or one function call is completed
        while (true) {
            ledlist[0] = 1;
            ledlist[1] = 0; ledlist[2] = 0;
        }

}

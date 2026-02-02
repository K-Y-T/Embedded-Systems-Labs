/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <array>

// Blinking rate in milliseconds
#define BLINKING_RATE     200ms

// Declare and define function for the Ping Pong blinking patterns of LEDs
void pingpong(std::array<DigitalOut, 3>& arr) {
    // Loop through the led array forwards
    for (int i = 0; i < 3; i++){
            // Led on
         arr[i] =  !arr[i];
        ThisThread::sleep_for(BLINKING_RATE);
            // Led off
        arr[i] =  !arr[i];
        ThisThread::sleep_for(BLINKING_RATE);
        }
    // Loopback effect by just blinking middle led
    // Middle Led on
    arr[1] =  !arr[1];
    ThisThread::sleep_for(BLINKING_RATE);
    // Middle Led off
     arr[1] =  !arr[1];
    ThisThread::sleep_for(BLINKING_RATE);

}

int main()
{
    // Create an array of size 3 of the DigitalOut class with the three led objects initialized within
    std::array<DigitalOut, 3> ledlist = {
        DigitalOut(LED1), 
        DigitalOut(LED2), 
        DigitalOut(LED3)
        };

    while (true) {
        pingpong (ledlist);
    }
}

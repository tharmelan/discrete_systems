/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"
#include <stdint.h>

#include "IIR_filter.h"


DigitalOut led(LED1);

int main()
{    
    IIR_filter firstOrder(.1,.01);
    IIR_filter secondOrder(15, 0.3, 0.01, 2.0);
    const int N=100;
    float u[N];
    float y[N];

    for(uint16_t k = 0; k<N; k++) {
        u[k] = 1.0*(k>=10);
        y[k] = secondOrder(u[k]);
        printf("%2.4f, %2.4f\n",u[k],y[k]);
    }



    while(1) 
    ;    
    

}

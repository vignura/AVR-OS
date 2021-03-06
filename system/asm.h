/*
 * Operating system for Atmel AVR microcontrollers
 * Copyright (c) 2015 Konrad Kusnierz <iryont@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _PORT_H
#define _PORT_H

#include "pch.h"

#define ENABLE_INTERRUPTS 	asm volatile("sei");
#define DISABLE_INTERRUPTS 	asm volatile("cli");

// interrupts
void osSetupTimerInterrupt();

// atomic
uint8_t osTAS(uint8_t *v);
uint8_t osCAS(uint8_t *v, uint8_t p, uint8_t q);

// stack
uint8_t* osInitializeStack(uint8_t* topOfStack, void (*taskFunction)(void*), void* taskParameter);

// yield
void osNonSavableYield(void) __attribute__ ((naked));
void osNonResumableYield(void) __attribute__ ((naked));
void osResumableYield(void) __attribute__ ((naked));

#endif

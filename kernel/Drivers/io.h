/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

I/O Header
*/

#ifndef _DRV_IO

#define _DRV_IO 1

#include <stdint.h>

static inline void outb(uint16_t port, uint8_t value)
{
    asm volatile ( "outb %0, %1" : : "a"(value), "Nd"(port) );
}

static inline uint8_t inb(uint16_t port)
{
    uint8_t ret;
    asm volatile ( "inb %1, %0"
                    : "=a"(ret)
                    : "Nd"(port) );
    return ret;
}

#endif
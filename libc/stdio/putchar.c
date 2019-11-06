/* KurtOS libc

(c) Kurt Carre 2019

Licensed under AGPL v3

putchar implementation
*/

#include <stdio.h>

#ifdef __KERNEL__
#include "terminal.h"
#endif

int putchar(int c)
{
    #ifdef __KERNEL__
    terminal_putchar((char)c);
    return 0;

    #else
    return (-1);
    #endif
    return c;
}
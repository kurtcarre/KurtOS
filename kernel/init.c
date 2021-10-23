/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Kernel Init
*/

#include "kernel.h"
#include "Drivers/terminal.h"

size_t strlen(const char* string)
{
    size_t len;
    while(string[len])
        len++;
    return len;
}

void term_print(const char* string)
{
    size_t len = strlen(string);
    for(size_t i = 0; i < len; i++)
    {
        terminal_putchar(string[i]);
    }
}

void kinit()
{
    //int ver = VER;

    terminal_init();

    term_print("Loading KurtOS version...");
}
/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Kernel Init
*/

#include "kernel.h"
#include "Drivers/terminal.h"
#include "libk/stdio.h"

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
    int ver = VER;

    terminal_init();

    term_print("Kernel starting...\n");

    printf("\nLoading KurtOS version %d ...", ver);
}
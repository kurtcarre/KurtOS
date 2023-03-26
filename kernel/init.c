/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Kernel Init
*/

#include "kernel.h"
#include "Drivers/terminal.h"
#include "libk/stdio.h"

/*void term_print(const char* string)
{
    size_t len = strlen(string);
    for(size_t i = 0; i < len; i++)
    {
        terminal_putchar(string[i]);
    }
}*/

void kinit()
{
    int ver = VER;

    terminal_init();

    printf("Kernel starting...\n");

    printf("\nLoading KurtOS version %d...", ver);

    int test1 = 322;
    int test2 = 5953532;
    int test3 = -14352523453;
    int test4 = -555666777;

    printf("\ntest1: %d, test2: %d, test3: %d, test4: %d\n", test1, test2, test3, test4);
    printf("test1: %x, test2: %x, test3: %x, test4: %x", test1, test2, test3, test4);
}
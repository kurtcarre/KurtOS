/* KurtOS libc

(c) Kurt Carre 2021

Licensed under AGPL v3

putchar implementation
*/

#include "../stdio.h"
#include "../../Drivers/terminal.h"

int putchar(int c)
{
    terminal_putchar((char)c);
    return 0;
}
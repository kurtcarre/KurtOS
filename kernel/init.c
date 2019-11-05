/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Kernel Init
*/
#include "kernel.h"
#include "terminal.h"
void kinit()
{
    int ver = VER;

    terminal_init();
}
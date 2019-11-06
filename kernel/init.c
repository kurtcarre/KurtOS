/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Kernel Init
*/

#include "kernel.h"
#include "terminal.h"
#include <stdio.h>

void kinit()
{
    int ver = VER;

    terminal_init();

    printf("Loading KurtOS version %d ...", ver);
}
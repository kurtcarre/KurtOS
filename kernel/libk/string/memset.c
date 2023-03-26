/* KurtOS Kernel

(c) Kurt Carre 2022

Licensed under AGPL v3

memset implementation
*/

#include "../string.h"

void* memset(void* addr, int value, size_t len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        ((char*)addr)[i] = value;
    }
}
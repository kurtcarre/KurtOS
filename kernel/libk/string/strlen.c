/* KurtOS Kernel

(c) Kurt Carre 2021

Licensed under AGPL v3

strlen implementation
*/

#include "../string.h"

size_t strlen(const char* string)
{
    size_t len = 0;
    while(string[len])
        len++;
    return len;
}
/* KurtOS libc

(c) Kurt Carre 2019

Licensed under AGPL v3

strlen implementation
*/

#include <string.h>

size_t strlen(const char* string)
{
    size_t len;
    while(string[len])
        len++;
    return len;
}
/* KurtOS libc

(c) Kurt Carre 2019

Licensed under AGPL v3

puts implementation
*/

#include <stdio.h>

int puts(const char* string)
{
    return printf("%s\n", string);
}
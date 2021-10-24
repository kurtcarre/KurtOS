/* KurtOS libc

(c) Kurt Carre 2021

Licensed under AGPL v3

string.h
*/

#ifndef _LIBK_STRING_H
#define _LIBK_STRING_H 1

#include <stddef.h>

size_t strlen(const char*);
void* memset(void*, int, size_t);
void* memcmp(const void*, const void*, size_t);
void* memmove(void*, const void*, size_t);
void* memcpy(void* __restrict, const void*, size_t);

#endif
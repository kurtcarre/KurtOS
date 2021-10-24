/* KurtOS libc

(c) Kurt Carre 2021

Licensed under AGPL v3

stdio.h
*/

#ifndef _LIBK_STDIO_H

#define _LIBK_STDIO_H 1

#define EOF (-1)

int printf(const char* restrict format, ...);
int putchar(int);
int puts(const char*);

#endif
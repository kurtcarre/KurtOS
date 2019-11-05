/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Terminal driver header
*/

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

void terminal_init();

void terminal_putchar(char c);

void terminal_setcolour(uint8_t colour);

void update_cursor();

void clear_screen();

enum vga_colour
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15
};

static inline uint8_t terminal_colour(enum vga_colour fg, enum vga_colour bg)
{
    return fg | bg << 4;
}

static inline uint16_t vga_entry(unsigned char c, uint8_t colour)
{
    return (uint16_t) c | (uint16_t) colour << 8;
}
/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Terminal driver
*/

#include "terminal.h"

static const size_t WIDTH = 80;
static const size_t HEIGHT = 25;

size_t term_row;
size_t term_column;
uint8_t term_colour;
uint16_t* term_buffer;

void terminal_init()
{
    term_row = 0;
    term_column = 0;
    term_colour = terminal_colour(GREEN, BLACK);
    term_buffer = (uint16_t*) 0xB8000;
    clear_screen();
}

void clear_screen()
{
    term_row = 0;
    term_colour = 0;
    for(size_t y = 0; y < HEIGHT; y++)
    {
        for(size_t x; x < WIDTH; x++)
        {
            terminal_putchar(' ');
        }
    }
    update_cursor();
}

void terminal_setcolour(uint8_t colour)
{
    term_colour = colour;
}

void terminal_putcharat(char c, uint8_t colour, size_t x, size_t y)
{
    size_t index = y * WIDTH + x;
    term_buffer[index] = vga_entry(c, colour);
}

void terminal_putchar(char c)
{
    switch (c)
    {
        case '\n':
            term_column = 0;
            if(++term_row == HEIGHT)
                term_row = 0;
            return;
        case '\t':
            term_column += 4;
            if(term_column >= WIDTH)
                term_column = 0;
                term_row++;
            return;
        case '\r':
            term_column = 0;
            return;
        default:
            terminal_putcharat(c, term_colour, term_column, term_row);
    }
    if(++term_column == WIDTH)
    {
        term_column = 0;
        if(++term_row == HEIGHT)
            term_row = 0;
    }
}

void update_cursor()
{
    
}
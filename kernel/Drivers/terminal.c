/* KurtOS Kernel

(c) Kurt Carre 2019

Licensed under AGPL v3

Terminal driver
*/

#include "terminal.h"
#include "io.h"

static const size_t WIDTH = 80;
static const size_t HEIGHT = 25;

static size_t term_row;
static size_t term_column;
static uint8_t term_colour;
static uint16_t* term_buffer;

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
    term_column = 0;
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

void terminal_putcharat(unsigned char c, uint8_t colour, size_t x, size_t y)
{
    const size_t index = y * WIDTH + x;
    term_buffer[index] = vga_entry(c, colour);
}

void terminal_putchar(char c)
{
    unsigned char uc = c;
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
            terminal_putcharat(uc, term_colour, term_column, term_row);
    }
    if(++term_column == WIDTH)
    {
        term_column = 0;
        if(++term_row == HEIGHT)
            term_row = 0;
    }
}

void move_cursor(size_t row, size_t column)
{
    unsigned short pos = (row*80) + column;

    outb(0x3D4, 0x0F);
    outb(0x3D5, (unsigned char)(pos&0xFF));
    outb(0x3D4, (unsigned char)((pos>>8)&0xFF));
}

void update_cursor()
{
    move_cursor(term_row, term_column);
}
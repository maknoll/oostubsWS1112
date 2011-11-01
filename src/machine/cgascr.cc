/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/
 
#include "machine/cgascr.h"
#include "machine/io_port.h"

#define ROWS 25
#define COLUMNS 80
#define LOW_BYTE 15
#define HIGH_BYTE 14
#define INDEX_REGISTER 0x3d4
#define DATA_REGISTER 0x3d5

CGA_Screen::CGA_Screen() {}
CGA_Screen::~CGA_Screen() {}

void CGA_Screen::setpos (unsigned short x, unsigned short y)
{
	cursor_t position;
    position.both = y*COLUMNS+x;
    
	IO_Port(INDEX_REGISTER).outb(LOW_BYTE);
	IO_Port(DATA_REGISTER).outb(position.low);

	IO_Port(INDEX_REGISTER).outb(HIGH_BYTE);
	IO_Port(DATA_REGISTER).outb(position.high);
}

void CGA_Screen::getpos(unsigned short& x, unsigned short& y) const
{
    cursor_t position;
	IO_Port(INDEX_REGISTER).outb(LOW_BYTE);
	position.low = IO_Port(DATA_REGISTER).inb();

	IO_Port(INDEX_REGISTER).outb(HIGH_BYTE);
	position.high = IO_Port(DATA_REGISTER).inb();

	x = position.both % 80;
	y = position.both / 80;
}

void CGA_Screen::show (unsigned short x, unsigned short y, char c, unsigned char attrib)
{
	char *cga = (char *) 0xb8000;

	unsigned int position = (y*COLUMNS+x)*2;
	cga[position] = c;
	cga[position+1] = attrib;
}

void CGA_Screen::print (const char* string, unsigned int n, unsigned char attrib)
{
	unsigned short i;
	unsigned short x = 0;
	unsigned short y = 0;
	
	getpos(x, y);

    if (y * COLUMNS + x + n > ROWS * COLUMNS) {
        scrollup();
        y--;
    }
    
	for (i = 0; i < n; i++) {
		if (string[i] == '\n') {
			y++;
			x = 0;
		} else {
		show (x++, y, string[i], attrib);
		}
	}

	setpos(x, y);
}

void CGA_Screen::scrollup ()
{
	char *cga = (char *) 0xb8000;
	
	for (int i = 0; i < (ROWS-1) * COLUMNS * 2; i++)
		cga[i] = cga[i+(COLUMNS*2)];
    for (int i = (ROWS-1) * COLUMNS * 2; i < ROWS * COLUMNS * 2; i++)
        cga[i] = 0;
}

void CGA_Screen::clear ()
{
	char *cga = (char *) 0xb8000;
	for (int i = 0; i < ROWS * COLUMNS * 2; i++)
		cga[i] = 0;
}

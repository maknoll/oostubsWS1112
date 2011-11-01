/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/strbuf.h"

Stringbuffer::Stringbuffer ()
{
	position=0;
}

Stringbuffer::~Stringbuffer () {}

void Stringbuffer::put (char c)
{
	if (position >= BUFFER_SIZE) {
		flush();	
	}
	buffer[position] = c;
	position++;
}

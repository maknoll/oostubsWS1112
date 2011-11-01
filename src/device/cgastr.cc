/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "device/cgastr.h"

#define WHITE_ON_BLACK 0x0F

CGA_Stream::CGA_Stream() {}

CGA_Stream::~CGA_Stream() {}

void CGA_Stream::flush ()
{
    print (buffer, position, WHITE_ON_BLACK);
	position = 0;
}

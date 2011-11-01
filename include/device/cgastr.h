/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                         C G A _ S T R E A M                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __cgastr_include__
#define __cgastr_include__

#include "object/o_stream.h"
#include "machine/cgascr.h"


class CGA_Stream  : public O_Stream, public CGA_Screen {
public:
    
	CGA_Stream ();
	~CGA_Stream ();
    
    virtual void flush();
};

#endif

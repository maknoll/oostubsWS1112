/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __o_stream_include__
#define __o_stream_include__

#include "object/strbuf.h"

class O_Stream : public Stringbuffer{
public:
    
    enum Base
    {
        bin=2,
        oct=8,
        dec=10,
        hex=16
    };
    
    Base digitBase;
    
    O_Stream();
    
    virtual ~O_Stream();
    
    O_Stream& operator << (char value); 
    
    O_Stream& operator << (unsigned char value);
    
    O_Stream& operator << (char* value);
    
    O_Stream& operator << (const char* value);
    
    O_Stream& operator << (unsigned short value); 
    
    O_Stream& operator << (short value); 
    
    O_Stream& operator << (unsigned int value);
    
    O_Stream& operator << (int value);
    
    O_Stream& operator << (unsigned long value);
    
    O_Stream& operator << (long value);
    
    O_Stream& operator << (void* value);
    
    O_Stream& operator << (O_Stream& (*f) (O_Stream&));
    
    friend O_Stream& endl(O_Stream&);
    friend O_Stream& bin(O_Stream&);
    friend O_Stream& oct(O_Stream&);
    friend O_Stream& dec(O_Stream&);
    friend O_Stream& hex(O_Stream&);
};

O_Stream& endl(O_Stream &out);

O_Stream& bin(O_Stream &out);

O_Stream& oct(O_Stream &out);

O_Stream& dec(O_Stream &out);

O_Stream& hex(O_Stream &out);

#endif

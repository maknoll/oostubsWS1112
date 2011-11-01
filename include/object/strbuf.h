/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                       S T R I N G B U F F E R                             *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __strbuf_include__
#define __strbuf_include__

#define BUFFER_SIZE 80

class Stringbuffer {
public:
	char buffer[BUFFER_SIZE];
	int position;
    
protected:
    
    Stringbuffer();
    
    virtual ~Stringbuffer();
    
    void put(char c); 
    
    virtual void flush() = 0;
};

#endif

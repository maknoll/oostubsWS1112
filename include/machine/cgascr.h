/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                             C G A _ S C R E E N                           *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __screen_include__
#define __screen_include__

class CGA_Screen {
	
public:
    
    CGA_Screen();
    
    ~CGA_Screen();
    
    void setpos(unsigned short x, unsigned short y);
    
    void getpos(unsigned short& x, unsigned short& y) const;
    
    void show(unsigned short x, unsigned short y, char c, unsigned char attrib);
    
    void print(const char* string, unsigned int n, unsigned char attrib);
    
    void scrollup();
    
    void clear();
    
    typedef union {
        struct {
            char low;
            char high;
        };
        unsigned short both;
    } cursor_t;
    
    typedef union {
        struct {
            char text: 4;
            char background: 3;
            char flashing: 1;
        };
        unsigned char attrib;
    } attrib_t;
};

#endif

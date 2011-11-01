/*****************************************************************************
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                            O _ S T R E A M                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#include "object/o_stream.h"

void longToString(long number, int base, char* output);

O_Stream::O_Stream()
{
	position = 0;
	digitBase = dec;
}

O_Stream::~O_Stream() {}

O_Stream& O_Stream::operator << (char value) {
	put(value);
	return *this;
}

O_Stream& O_Stream::operator << (unsigned char value) {
    put((char)(value));
    return *this;
}

O_Stream& O_Stream::operator << (char* value){
    int pos = 0;
    while (value[pos] > 0){
	  	put(value[pos++]);
    }
    return *this;
}

O_Stream& O_Stream::operator << (const char* value) {
	return *this << (char*) value;
}

O_Stream& O_Stream::operator << (unsigned short value) {
	return *this << (unsigned int) value;
}

O_Stream& O_Stream::operator << (short value) {
	return *this << (int) value;
}

O_Stream& O_Stream::operator << (unsigned int value) {
	return *this << (unsigned long) value;
}

O_Stream& O_Stream::operator << (int value) {
    return *this << (long) value;
}

O_Stream& O_Stream::operator << (unsigned long value) {
    char output[130];
    longToString(value,digitBase,output);
    
    return *this << output;
}

O_Stream& O_Stream::operator << (long value) {
	char output[130];
    
	if(value<0){
		value *= -1;
		*this << '-';
	}
    
	longToString(value,digitBase,output);
    
	return *this << output;
}

O_Stream& O_Stream::operator << (void* value) {
	char output[5];
	longToString((unsigned long)value,hex,output);
	return *this << output;
}


O_Stream& O_Stream::operator << (O_Stream& (*f) (O_Stream&)) {
    return (*f)(*this);
}

O_Stream& endl (O_Stream& out) {
	out.put('\n');
	out.flush();
	return out;
}

O_Stream& bin(O_Stream &out) {
    out.digitBase = O_Stream::bin;
    return out;
}

O_Stream& oct(O_Stream& out) {
	out.digitBase = O_Stream::oct;
	return out;
}

O_Stream& dec(O_Stream& out) {
	out.digitBase = O_Stream::dec;
	return out;
}

O_Stream& hex(O_Stream& out) {
	out.digitBase = O_Stream::hex;
    return out;
}

void longToString(long number,int base, char* output) {
	int rest = 0;
	int strPoint = 0;
    char tempString[80];
    
    if (number == 0){
		output[0] = '0';
        output[1] = 0;
		return;
	}
    
	while (number>0) {
		rest = number%base;
		number /= base;
		if (rest > 9) {
			tempString[strPoint++] = (char)(rest + 55);
		} else {
			tempString[strPoint++] = (char)(rest + 48);
		}
	}
    
    int up = 0;
	for (int down = strPoint-1; down >= 0; down--, up++) {
		output[up] = tempString[down];
	}
	output[up] = 0;
}

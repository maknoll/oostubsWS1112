#include "user/task3.h"
#include "device/cgastr.h"
#include "machine/cpu.h"
#include "guard/secure.h"

extern CGA_Stream kout;
extern CPU cpu;

Task3::Task3(){
	kout.setpos(31,1);
	kout << "OOStuBs - Task 3" << endl << endl;

	cpu.enable_int();
}

Task3::~Task3(){

	cpu.disable_int();
}

void Task3::action(){
	unsigned short x,y;
	unsigned char i=0;

	{
		Secure s;
		kout.getpos(x,y);
	}
	while(1)
	{
		Secure s;
		kout.setpos(x,y);
		for(unsigned short j=0;j<39;j++)
			kout << "-";
			kout.flush();
		switch(i++%4)
		{
			case(0): kout << "//";
					 break;
			case(1): kout << "--";
					 break;
			case(2): kout << "\\\\";
					 break;
			case(3): kout << "||";
					 break;
		}
		for(unsigned short j=0;j<39;j++)
			kout << "-";
		kout << endl;
	}
}

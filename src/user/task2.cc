#include "user/task2.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

extern CGA_Stream kout;
extern CPU cpu;

Task2::Task2(){
    kout.clear();
	kout.setpos(31,1);
	kout << "OOStuBs - Task 2" << endl << endl;

	cpu.enable_int();
}

Task2::~Task2(){

	cpu.disable_int();
}

void Task2::action(){
	unsigned short x,y;
	unsigned char i=0;

	kout.getpos(x,y);
	while(1)
	{
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
        int i;
        for (i=1 ; i<200000 ; i++) ;
	}
}

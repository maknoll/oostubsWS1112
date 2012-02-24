#include "user/task5.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "syscall/guarded_scheduler.h"
#include "guard/secure.h"
#include "machine/cpu.h"

extern CGA_Stream kout;
extern Keyboard keyboard;
extern Guarded_Scheduler scheduler;
extern CPU cpu;

unsigned char Task5::stacks[Task5::numStacks][Task5::stackSize];

Task5::RotCursor::RotCursor(unsigned char *stack, unsigned short x, unsigned short y)
				  : Application(stack)
{
	this->i=0;
	this->x=x;
	this->y=y;
}

void Task5::RotCursor::action(){
	while(true)
	{
		Secure s;
		kout.flush();
		kout.setpos(x, y);
		switch(i++%4)
		{
			case(0):	kout << '|';
						break;
			case(1):	kout << '/';
						break;	
			case(2):	kout << '-';
						break;
			case(3):	kout << '\\';
						break;
		}
		kout.flush();
	}
}

Task5::Counter::Counter(unsigned char *stack, unsigned short x, unsigned short y) : Application(stack)
{
	this->i=0;
	this->x=x;
	this->y=y;
}

void Task5::Counter::action(){
	while(true)
	{
		Secure s;
		kout.flush();
		kout.setpos(x, y);
		kout << "Counter: " << i++ << endl;
	}
}

Task5::Task5() : Application(stacks[task5Stack]+stackSize),
				 rotCursor(stacks[rotCursorStack]+stackSize, rotCursorX, rotCursorY),
				 counter1(stacks[counter1Stack]+stackSize, counter1X, counter1Y),
				 counter2(stacks[counter2Stack]+stackSize, counter2X, counter2Y)
{
	kout.setpos(31,1);
	kout << "OOStuBs - Task 5" << endl << endl;
}

void Task5::action(){
	cpu.enable_int();
	scheduler.ready(rotCursor);
	scheduler.ready(counter1);
	scheduler.ready(counter2);
}

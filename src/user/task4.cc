#include "user/task4.h"
#include "device/cgastr.h"
#include "device/keyboard.h"
#include "thread/scheduler.h"
#include "machine/cpu.h"

extern CGA_Stream kout;
extern Keyboard keyboard;
extern Scheduler scheduler;
extern CPU cpu;

unsigned char Task4::stacks[Task4::numStacks][Task4::stackSize];

Task4::RotCursor::RotCursor(unsigned char* stack, unsigned short x, unsigned short y)
				: Application(stack)
{
	this->i=0;
	this->x=x;
	this->y=y;
}

void Task4::RotCursor::action(){
	while(true)
	{
		kout.flush();
		kout.setpos(x,y);
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
		resume();
	}
}

Task4::Counter::Counter(unsigned char* stack, unsigned short x, unsigned short y) 
			   : Application(stack)
{
	this->i=0;
	this->x=x;
	this->y=y;
}

void Task4::Counter::action(){
	while(true)
	{
		kout.flush();
		kout.setpos(x,y);
		kout << "Counter: " << i++ << endl;
		if(i%100000==0)
			resume();
	}
}

Task4::KeyLogger::KeyLogger(unsigned char* stack, unsigned short x, unsigned short y)
				 : Application(stack)
{
	this->x=x;
	this->y=y;
}

void Task4::KeyLogger::action(){
	while(true)
	{
		Key k;
		kout.flush();
		kout.setpos(x,y);
		kout << "Key: ";
		k=keyboard.key_hit();
		if(k.valid())
			kout << k.ascii() << endl;
		resume();
	}
}

Task4::Task4() : Application(stacks[task4Stack]+stackSize),
				 rotCursor(stacks[rotCursorStack]+stackSize, rotCursorX, rotCursorY),
				 counter1(stacks[counter1Stack]+stackSize, counter1X, counter1Y),
				 counter2(stacks[counter2Stack]+stackSize, counter2X, counter2Y),
				 keyLogger(stacks[keyLoggerStack]+stackSize, keyLoggerX, keyLoggerY)
{
	kout.setpos(31,1);
	kout << "OOStuBs - Task 4" << endl << endl;
}

void Task4::action(){
	cpu.disable_int();
	scheduler.ready(rotCursor);
	scheduler.ready(counter1);
	scheduler.ready(counter2);
	scheduler.ready(keyLogger);
}

#include "user/appl.h"

/** \brief Fourth test application
 *
 * Showing the functionality of coroutine scheduling, by starting 4 coroutine
 * based applications.
 **/
class Task4 : public Application{
	private:
		/** \brief Stack name declaration **/
		enum StackNames{
			task4Stack,		/**<index of the stack of task4**/
			rotCursorStack,	/**<index of the stack of the rotating cursor**/
			counter1Stack,	/**<index of the stack of the first counter**/
			counter2Stack,	/**<index of the stack of the second counter**/
			keyLoggerStack,	/**<index of the stack of the keyboard printer**/
			numStacks		/**<number of stacks**/
		};

		/** \brief Parameters for the sub applications **/
		enum Constants{
			stackSize=1024,			/**< size of the stacks of the applications **/
			rotCursorX=79,			/**< X position of the rotating cursor on the screen **/
			rotCursorY=0,			/**< Y position of the rotating cursor on the screen **/
			counter1X=10,			/**< X position of the first counter on the screen **/
			counter1Y=10,			/**< Y position of the first counter on the screen **/
			counter2X=10,			/**< X position of the second counter on the screen **/
			counter2Y=15,			/**< Y position of the second counter on the screen **/
			counterIter=1000000,	/**< Number of iterations before resuming **/
			keyLoggerX=10,			/**< X position of the keyboard output on the screen **/
			keyLoggerY=20			/**< Y position of the keyboard output on the screen **/
		};

/** \brief statically created stacks for the applications **/
static unsigned char stacks[numStacks][stackSize];

/** \brief %Rotating symbol application
 *
 * This coroutine creates a rotating symbol in the upper left corner of the
 * screen, to show "quasi"-parallel execution of coroutines
 **/
class RotCursor : public Application
{
	private:
		/**\brief internal state to save current symbol **/
		unsigned char i;
		/**\brief internal position to print symbol to **/
		unsigned short x,y;

	public:
		/** \brief Default constructor
		 *
		 * Setting the start symbol
		 **/
		RotCursor(unsigned char* stack, unsigned short x, unsigned short y);

		/** \brief start outputting the symbol
		 *
		 * This method resumes after each iteration
		 **/
		virtual void action();
};

/** \brief Counting application
 *
 * This coroutine counts a value on a fixed position on the screen.
 * It is a greedy application, that eat a lot of CPU cycles before resuming.
 **/
class Counter : public Application
{
	private:
		/** \brief current counter value **/
		unsigned int i;
		/**\brief internal position to print counter value to **/
		unsigned short x,y;

	public:
		/** \brief Default constructor
		 *
		 * Setting the counter to 0
		 **/
		Counter(unsigned char* stack, unsigned short x, unsigned short y);

		/** \brief start outputting and incrementing the counter value
		 *
		 * This method resumes after counterIter iterations
		 **/
		virtual void action();
};

/** \brief %Key logging application
 *
 * This coroutine imitates the first task, by polling the keyboard controller
 * and outputting the keys on a fixed position on the screen
 **/
class KeyLogger : public Application
{
	private:
		/**\brief internal position to print keys to **/
		unsigned short x,y;
		
	public:
		/** \brief Default constructor **/
		KeyLogger(unsigned char* stack, unsigned short x, unsigned short y);

		/** \brief start outputting the fetched keys
		 *
		 * This method resumes after each interation
		 **/
		virtual void action();
};
		/** \brief Application for a rotating symbol **/
		RotCursor rotCursor;
		/** \brief Application for a printed out counter 1**/
		Counter counter1;
		/** \brief Application for a printed out counter 2**/
		Counter counter2;
		/** \brief Application for key output **/
		KeyLogger keyLogger;

	public:
		/** \brief Default Constructor 
		 *
		 * Setting the applications up
		 **/
		Task4();

		/** \brief start operation
		 *
		 * registers the applications with the scheduler and exit
		 **/
		virtual void action();
};

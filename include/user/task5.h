#include "user/appl.h"

/** \brief Fifth test application
 *
 * Showing the functionality of thread scheduling, by starting 3 thread
 * based applications.
 **/
class Task5 : public Application{
	private:
/** \brief Declaration of stack names for application stacks **/
enum StackNames{
	task5Stack,		/**< Stack of the Task itself **/
	rotCursorStack, /**< Stack of the rotating Cursor **/
	counter1Stack,  /**< Stack of the first Counter **/
	counter2Stack,  /**< Stack of the second Counter **/
	numStacks       /**< number of stacks in example Task **/
};

/** \brief Constants used in example Task **/
enum Constants{
	stackSize=1024,	/**< size of the stacks **/
	rotCursorX=79,	/**< X position of the rotating cursor on the screen **/
	rotCursorY=0,	/**< Y position of the rotating cursor on the screen **/
	counter1X=10,	/**< X position of the first counter on the screen **/
	counter1Y=10,	/**< Y position of the first counter on the screen **/
	counter2X=10,	/**< X position of the second counter on the screen **/
	counter2Y=15,	/**< Y position of the second counter on the screen **/
};

/**\brief globally declared byte array to be used as stacks for applications **/
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
		/**\brief x and y position for the output on the screen **/
		unsigned short x, y;

	public:
		/** \brief Default constructor
		 *
		 * Setting the start symbol
		 **/
		RotCursor(unsigned char* stack, unsigned short x, unsigned short y);

		/** \brief start outputting the symbol
		 *
		 * This method resumes after each interation
		 **/
		virtual void action();
};

/** \brief Counting application
 *
 * This coroutine counts a value on a fixed position on the screen
 **/
class Counter : public Application
{
	private:
		/** \brief current counter value **/
		unsigned int i;
		/**\brief x and y position for the output on the screen **/
		unsigned short x, y;

	public:
		/** \brief Default constructor
		 *
		 * Setting the counter to 0
		 **/
		Counter(unsigned char* stack, unsigned short x, unsigned short y);

		/** \brief start outputting and incrementing the counter value
		 *
		 * This method resumes after each interation
		 **/
		virtual void action();
};

		/** \brief Application for a rotating symbol **/
		RotCursor rotCursor;
		/** \brief Application for a printed out counter **/
		Counter counter1;
		/** \brief Application for a printed out counter **/
		Counter counter2;

	public:
		/** \brief Default Constructor 
		 *
		 * Setting the applications up
		 **/
		Task5();

		/** \brief start operation
		 *
		 * registers the applications with the scheduler and exit afterwards
		 **/
		virtual void action();
};

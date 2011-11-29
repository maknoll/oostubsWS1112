#include "user/appl.h"

/** \brief Third test application
 *
 * This application test the functionality of the implemented interrupt
 * synchronization system.  It prints the task identification and then
 * repeatedly draws a line in a secured section.  Interrupts from the keyboard
 * are printed onto the screen to a fixed location. This should not disturb the
 * drawing of the line anymore.
 **/
class Task3 : public Application{
	public:
		/** \brief Default constructor
		 *
		 * prints task information and enables interrupts
		 **/
		Task3();

		/** \brief Destructor
		 *
		 * disables interrupts, should never be called due to the endless loop
		 **/
		virtual ~Task3();

		/** \brief prints the line **/
		virtual void action();
};

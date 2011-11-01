/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                              I O _ P O R T                                *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __io_port_include__
#define __io_port_include__

/** \brief Accessor for I/O-Space
 *
 * Every computer uses a separate I/O memory that is only adressable by 
 * the methods <code>'in'</code> and <code>'out'</code>.
 * Each instance of IO_Port is an abstraction of an adress in that memory.
 * Using those abstractions adresses in memory can be accessed like ports. 
 */
class IO_Port {
  /** \brief adress of the port in the I/O adress space */
  unsigned short address;
public:
  /** \brief Default constructor setting the port **/
  IO_Port (unsigned short a) : address (a) {};

  /** \brief write a byte value to the associated port.
   *
   * @param val byte value to write
   */
  void outb (unsigned char val) const {
	asm("outb %1, %0"
		:
		:"d"(address), "a"(val)
		);
  };

  /** \brief  write a word value to the associated port.
   *
   * @param val word value to write
   */
  void outw (unsigned short val) const { 
	asm("out %1, %0"
		:
		:"d"(address), "a"(val)
		);
  };

  /** \brief read a byte value from the associated port.
   *
   * @return the read byte value
   */
  unsigned char inb () const {
	volatile char val=0;
    asm(
		"in %0, %%al\t\n"
		"mov %%al, (%1)"
		:
		:"d"(address), "r"(&val)
		:"%al"
		);
	return val;
  };

  /** \brief read a word value from the associated port.
   *
   * @return the read word value
   */
  unsigned short inw () const { 	
	volatile short val=0;
    asm(
		"in %0, %%ax\t\n"
		"mov %%ax, (%1)"
		:
		:"d"(address), "r"(&val)
		:"%ax"
		);
	return val;
  };
};

#endif

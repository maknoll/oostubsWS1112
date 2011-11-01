#ifndef __task1_header__
#define __task1_header__

#include "machine/multiboot.h"
#include "user/appl.h"
#include "stdint.h"

/** \brief First test application
 *
 * This application test the functionality of the implemented CGA and keyboard
 * driver. It does some printout of numerical values, as well as multiboot
 * information, passed by the multiboot compliant bootloader. To test the
 * keyboard the pushed keys are printed out to a fixed location on the screen
 **/

class Task1 : public Application
{
	private:
		/** \brief Information flags describing provided infromation **/
		enum Flags
		{
			memSize=1<<0,	/**< memory size information is provided **/
			bootDev=1<<1,	/**< boot device infromation is provided **/
			cmdLine=1<<2,	/**< command line infromation is provided **/
			modules=1<<3,	/**< loaded module infromation is provided **/
			aOut=1<<4,		/**< a.out executable infromation is provided **/
			elf=1<<5,		/**< elf executable infromation are provided **/
			memMap=1<<6		/**< memory map infromation is provided **/
		};


		/* Symbol table for a.out executables **/
		struct AOut_Symbol_Table
		{
			uint32_t tabsize;
			uint32_t strsize;
			uint32_t addr;
			uint32_t reserved;
		};

		/* Section header table for ELF executables */
		struct ELF_Section_Header_Table
		{
			uint32_t num;
			uint32_t size;
			uint32_t addr;
			uint32_t shndx;
		};

		/* Loaded module information. **/
		struct Module
		{
			uint32_t mod_start;
			uint32_t mod_end;
			uint32_t string;
			uint32_t reserved;
		};

		/* Memory map information
		 *
		 * Be careful that the offset 0 is base_addr_low but not size.
		 **/
		struct Memory_Map
		{
			uint32_t size;
			uint32_t base_addr_low;
			uint32_t base_addr_high;
			uint32_t length_low;
			uint32_t length_high;
			uint32_t type;
		};

	public:
		/* Multiboot information **/
		struct Multiboot_Info
		{
			uint32_t flags;
			uint32_t mem_lower;
			uint32_t mem_upper;
			uint32_t boot_device;
			uint32_t cmdline;
			uint32_t mods_count;
			uint32_t mods_addr;
			union
			{
				AOut_Symbol_Table aout;
				ELF_Section_Header_Table elf;
			} executable_info;
			uint32_t mmap_length;
			uint32_t mmap_addr;
		};

	private:

		/** \brief magic value provided by multiboot compliant bootloaders **/
		uint32_t magic;

		/** \brief pointer to multiboot information structure **/
		const Multiboot_Info* mbi;

		/**\brief check the multiboot infromation struct for provided information
		 *
		 * \param flag which information is requested
		 * \return true if provided, false otherwise
		 **/
		bool checkFlag(Flags flag);

		/** \brief parse and print the multiboot information **/
		void parseAndPrint();

		/** \brief test the functionality of the Kout object **/
		void testKout();

		/** \brief test the functionality of the Keyboard_Controller object **/
		void testKeyboard();

	public:
		/** \brief Constructor
		 *
		 * \param magic bootloader provided magic value
		 * \param mbi pointer to multiboot info structure
		 **/
		Task1(uint32_t magic, const ::Multiboot_Info* mbi);

		/** \brief parse and print multiboot information
		 *
		 * test also the implementation of CGA_Stream and Keyboard_Controller
		 **/

		virtual void action();
};

#endif

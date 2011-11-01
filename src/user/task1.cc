#include "user/task1.h"
#include "device/cgastr.h"
#include "machine/keyctrl.h"

extern CGA_Stream kout;
extern Keyboard_Controller keyboard;

Task1::Task1(uint32_t magic, const ::Multiboot_Info* mbi)
	: Application(), magic(magic), mbi(reinterpret_cast<const Multiboot_Info*>(mbi)) {

}

bool Task1::checkFlag(Flags flag)
{
	return (mbi->flags&flag);
}

void Task1::parseAndPrint(){

	if( magic != MULTIBOOT_BOOTLOADER_MAGIC )
	{
		kout << "Not booted by multiboot compliant loader" << endl;
		return;
	}

	kout << "flags= " << bin << mbi->flags << dec << endl;

	if (checkFlag(memSize))
		kout << "mem_lower = " << mbi->mem_lower
			 << "KB, mem_upper = " << mbi->mem_upper 
			 << "KB" << endl;

	if (checkFlag(bootDev))
		kout << "boot_device = " << hex << mbi->boot_device << endl;

	if (checkFlag(cmdLine))
		kout << "cmdline = " << (const char*)mbi->cmdline << endl;

	if (checkFlag(modules))
	{
		kout << "mods_count = " << dec << mbi->mods_count 
			 << ", mods_addr = " << hex << mbi->mods_addr << endl;

		Module *mod=reinterpret_cast<Module*>(mbi->mods_addr);
		for(uint32_t i=0;i < mbi->mods_count; i++)
		{
		       kout << " mod_start = " << mod->mod_start
				    << ", mod_end = " << mod->mod_end 
					<< ", string = " << mod->string << endl;
		       mod++;
		}
	}

	if (checkFlag(aOut) && checkFlag(elf))
	{
		kout << "Both bits 4 and 5 are set." << endl;
		return;
	}

	if (checkFlag(aOut))
	{
		const AOut_Symbol_Table *aout_sym = &(mbi->executable_info.aout);

		kout << "aout_symbol_table: tabsize = " 
			 << dec << aout_sym->tabsize << endl
		     << "strsize = " << aout_sym->strsize
			 << ", addr = " << hex << aout_sym->addr << endl;
	}

	if (checkFlag(elf))
	{
		const ELF_Section_Header_Table *elf_sec = &(mbi->executable_info.elf);

		kout << "elf_sec: num = "<< dec << elf_sec->num 
			 << ", size = " << elf_sec->size << endl
		     << " addr = " << hex << elf_sec->addr
			 << ", shndx = " << elf_sec->shndx << endl;
	}

	if (checkFlag(memMap))
	{

		kout << "mmap_addr = " << hex << mbi->mmap_addr
			 << ", mmap_length = " << dec << mbi->mmap_length << endl;

		for( const char* curr = (const char*)mbi->mmap_addr;
			curr < (const char*)mbi->mmap_addr + mbi->mmap_length ;
			curr+= ((const Memory_Map*)curr)->size + sizeof(((const Memory_Map*)curr)->size) )
		{
			const Memory_Map* currEntry=reinterpret_cast<const Memory_Map*>(curr);

			kout << " base_addr = " << hex << currEntry->base_addr_low;
			if(currEntry->length_low<1024)
			     kout << ", length = " << dec << currEntry->length_low << "B";
			else if(currEntry->length_low<1024*1024)
				 kout << ", length = " << dec << currEntry->length_low/1024 << "kB";
			else if(currEntry->length_low<1024*1024*1024)
				 kout << ", length = " << dec << currEntry->length_low/(1024*1024) << "MB";
			else
				 kout << ", length = " << dec << currEntry->length_low/(1024*1024*1024) << "GB";

			kout << ", type = " 
				 << ((currEntry->type==0x1)?"ram":"reserved") << endl;
		}
	}
}

void Task1::testKout()
{
	unsigned short x,y;
	kout << endl << "Kout test:" << endl;
	kout.getpos(x,y);
	for(unsigned int i=0;i<18;i++)
	{
		if(i%6==0)
		{
			kout.flush();
			kout.setpos(0,y+1+i/6);
		}
		kout << dec << "(" << i << ", " << hex << i << ") ";
	}
	kout << endl << endl << endl;
}

void Task1::testKeyboard()
{
	unsigned short x,y;
	kout << endl << "Keyboard test: ";
	kout.flush();
	kout.getpos(x,y);

	while(true){
		Key k=keyboard.key_hit();
		if(k.valid()){
			kout.setpos(x,y);
			kout << k.ascii();
			kout.flush();
		}
	}
}

void Task1::action()
{
    kout.clear();
	kout.setpos(36, 1);
	kout << "OOStuBs" << endl;

	testKout();

	parseAndPrint();

//    kout.scrollup();
    
	testKeyboard(); 
}

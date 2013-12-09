//------------------------------------------------------------------------------
// vme_io_wxp: Controls Bit3 for A24D16 read/write DUMMY version
///------------------------------------------------------------------------------
	extern long int vme_open()
{
	return 0;
}
//------------------------------------------------------------------------------
// vme_write:  writes A24D16 data
//--------------------------------------------------------------------
	extern long int vme_write(unsigned long &adr, unsigned short &wr_data)
{
	return 0;
}

//------------------------------------------------------------------------------
// vme_bwrite:  writes A24D16 block data
//------------------------------------------------------------------------------
	extern long int vme_bwrite(unsigned long &adr, unsigned short &wr_data, unsigned long &nbytes)
{
	return 0;
}

//------------------------------------------------------------------------------
// vme_read:  reads A24D16 data
//------------------------------------------------------------------------------
	extern long int vme_read(unsigned long &adr, unsigned short &rd_data)
{
	rd_data=0;
	return 0;
}
//------------------------------------------------------------------------------
// vme_close:  closes Bit3 controller
//------------------------------------------------------------------------------
	extern long int vme_close()
{
    return 0;
}

//------------------------------------------------------------------------------
// vme_errs:	Change bus timeout error print
//				print_mode=0 prints bt errors
//				print_mode=1 suppresses error printing
//------------------------------------------------------------------------------
	extern long int vme_errs(unsigned long &print_mode)
{
    return 0;
}
//------------------------------------------------------------------------------
// End vme_io_wxp.c DUMMy
//------------------------------------------------------------------------------

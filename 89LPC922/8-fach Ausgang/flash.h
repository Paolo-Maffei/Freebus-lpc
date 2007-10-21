/* $Id$ */

void write_byte(unsigned char addrh, unsigned char addrl, unsigned char zdata)
{
  FMCON=0x00;		// read command
  FMADRH=addrh+0x1A;
  FMADRL=addrl;
  FMDATA=zdata;
  FMCON=0x68;		// write command
}


unsigned char read_byte(unsigned char addrh, unsigned char addrl)
{
  unsigned char zdata;
  
  zdata=dataflash[(addrh<<8)+addrl];
  return (zdata);
}

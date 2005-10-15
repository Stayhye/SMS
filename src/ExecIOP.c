#include "ExecIOP.h"

#include <loadfile.h>

static unsigned char s_ExecIOP[] __attribute__(   (  aligned( 16 )  )   ) = {
	0x7f, 0x45, 0x4c, 0x46, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x80, 0xff, 0x08, 0x00, 0x01, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 
	0x10, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x34, 0x00, 0x20, 0x00, 0x02, 0x00, 0x28, 0x00, 
	0x08, 0x00, 0x07, 0x00, 0x80, 0x00, 0x00, 0x70, 0x74, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 
	0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x40, 0x00, 0x00, 0x00, 0x50, 0x82, 0x00, 0x00, 
	0x40, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x21, 0x20, 0x85, 0x00, 0x08, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x86, 0xa0, 0x00, 0x00, 0xc2, 0x80, 
	0x00, 0x00, 0xc3, 0x90, 0x08, 0x00, 0x40, 0x10, 0x00, 0x00, 0x00, 0x00, 0x21, 0x10, 0x85, 0x00, 
	0x00, 0x00, 0x43, 0xa0, 0x01, 0x00, 0xc6, 0x24, 0x00, 0x00, 0xc2, 0x80, 0x00, 0x00, 0xc3, 0x90, 
	0xfa, 0xff, 0x40, 0x14, 0x01, 0x00, 0xa5, 0x24, 0x08, 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0x00, 
	0xd0, 0xff, 0xbd, 0x27, 0x72, 0x00, 0x02, 0x24, 0x10, 0x00, 0xa2, 0xa3, 0x02, 0x00, 0x02, 0x24, 
	0x2c, 0x00, 0xbf, 0xaf, 0x06, 0x00, 0x82, 0x10, 0x28, 0x00, 0xb0, 0xaf, 0x2c, 0x00, 0xbf, 0x8f, 
	0x28, 0x00, 0xb0, 0x8f, 0x01, 0x00, 0x02, 0x24, 0x08, 0x00, 0xe0, 0x03, 0x30, 0x00, 0xbd, 0x27, 
	0x04, 0x00, 0xa2, 0x8c, 0x6f, 0x00, 0x03, 0x24, 0x11, 0x00, 0xa3, 0xa3, 0x00, 0x00, 0x45, 0x80, 
	0xc7, 0xff, 0x03, 0x24, 0x42, 0x00, 0xa3, 0x10, 0xd1, 0xff, 0x02, 0x24, 0xf3, 0xff, 0xa2, 0x14, 
	0x6d, 0x00, 0x02, 0x24, 0x10, 0x00, 0xa4, 0x27, 0x04, 0x00, 0x05, 0x24, 0x3a, 0x00, 0x06, 0x24, 
	0x00, 0x00, 0x00, 0x0c, 0x12, 0x00, 0xa2, 0xa3, 0x30, 0x00, 0x02, 0x24, 0x00, 0x00, 0x06, 0x3c, 
	0x40, 0x02, 0xc6, 0x24, 0x10, 0x00, 0xa4, 0x27, 0x05, 0x00, 0x05, 0x24, 0x03, 0x00, 0x00, 0x0c, 
	0x13, 0x00, 0xa2, 0xa3, 0x44, 0x00, 0x02, 0x24, 0x10, 0x00, 0xa4, 0x27, 0x08, 0x00, 0x05, 0x24, 
	0x44, 0x00, 0x06, 0x24, 0x17, 0x00, 0xa2, 0xa3, 0x00, 0x00, 0x00, 0x0c, 0x52, 0x00, 0x10, 0x24, 
	0x10, 0x00, 0xa4, 0x27, 0x0a, 0x00, 0x05, 0x24, 0x56, 0x00, 0x06, 0x24, 0x00, 0x00, 0x00, 0x0c, 
	0x19, 0x00, 0xb0, 0xa3, 0x20, 0x00, 0xa7, 0x27, 0x10, 0x00, 0xa4, 0x27, 0x21, 0x28, 0x00, 0x00, 
	0x21, 0x30, 0x00, 0x00, 0x89, 0x00, 0x00, 0x0c, 0x1b, 0x00, 0xa0, 0xa3, 0x31, 0x00, 0x02, 0x24, 
	0x10, 0x00, 0xa4, 0x27, 0x05, 0x00, 0x05, 0x24, 0x45, 0x00, 0x06, 0x24, 0x00, 0x00, 0x00, 0x0c, 
	0x13, 0x00, 0xa2, 0xa3, 0x10, 0x00, 0xa4, 0x27, 0x07, 0x00, 0x05, 0x24, 0x4f, 0x00, 0x06, 0x24, 
	0x00, 0x00, 0x00, 0x0c, 0x16, 0x00, 0xb0, 0xa3, 0x00, 0x00, 0x06, 0x3c, 0x44, 0x02, 0xc6, 0x24, 
	0x10, 0x00, 0xa4, 0x27, 0x03, 0x00, 0x00, 0x0c, 0x08, 0x00, 0x05, 0x24, 0x10, 0x00, 0xa4, 0x27, 
	0x0a, 0x00, 0x05, 0x24, 0x00, 0x00, 0x00, 0x0c, 0x52, 0x00, 0x06, 0x24, 0x10, 0x00, 0xa4, 0x27, 
	0x0c, 0x00, 0x05, 0x24, 0x21, 0x30, 0x00, 0x00, 0x56, 0x00, 0x02, 0x24, 0x00, 0x00, 0x00, 0x0c, 
	0x1b, 0x00, 0xa2, 0xa3, 0x10, 0x00, 0xa4, 0x27, 0x21, 0x28, 0x00, 0x00, 0x21, 0x30, 0x00, 0x00, 
	0x8b, 0x00, 0x00, 0x0c, 0x20, 0x00, 0xa7, 0x27, 0x17, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
	0x80, 0xbf, 0x05, 0x3c, 0x80, 0xbf, 0x06, 0x3c, 0x90, 0xbf, 0x03, 0x3c, 0x04, 0x14, 0xa5, 0x34, 
	0x0c, 0x14, 0xc6, 0x34, 0x00, 0x08, 0x63, 0x34, 0x90, 0xbf, 0x02, 0x3c, 0x80, 0xbf, 0x04, 0x3c, 
	0x00, 0x00, 0xa2, 0xac, 0xf0, 0x10, 0x84, 0x34, 0x00, 0x00, 0xc3, 0xac, 0x00, 0x00, 0x82, 0x8c, 
	0x08, 0x00, 0x03, 0x3c, 0x25, 0x10, 0x43, 0x00, 0x80, 0xbf, 0x06, 0x3c, 0x00, 0x00, 0x82, 0xac, 
	0x70, 0x15, 0xc6, 0x34, 0x00, 0x00, 0xc2, 0x8c, 0x80, 0xbf, 0x05, 0x3c, 0x0b, 0x20, 0x03, 0x3c, 
	0x80, 0xbf, 0x04, 0x3c, 0xe1, 0x31, 0x63, 0x34, 0x08, 0x00, 0x42, 0x34, 0x14, 0x10, 0xa5, 0x34, 
	0x14, 0x14, 0x84, 0x34, 0x00, 0x00, 0xc2, 0xac, 0x00, 0x00, 0xa3, 0xac, 0x17, 0x00, 0x00, 0x08, 
	0x00, 0x00, 0x83, 0xac, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0xe0, 0x41, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x6d, 0x6f, 0x64, 0x6c, 
	0x6f, 0x61, 0x64, 0x00, 0x08, 0x00, 0xe0, 0x03, 0x07, 0x00, 0x00, 0x24, 0x08, 0x00, 0xe0, 0x03, 
	0x0b, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x41, 0x44, 0x00, 0x00, 0x4d, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x2e, 0x73, 0x68, 0x73, 0x74, 0x72, 0x74, 0x61, 0x62, 0x00, 0x2e, 0x69, 0x6f, 0x70, 0x6d, 
	0x6f, 0x64, 0x00, 0x2e, 0x72, 0x65, 0x6c, 0x2e, 0x74, 0x65, 0x78, 0x74, 0x00, 0x2e, 0x72, 0x6f, 
	0x64, 0x61, 0x74, 0x61, 0x00, 0x2e, 0x64, 0x61, 0x74, 0x61, 0x00, 0x2e, 0x62, 0x73, 0x73, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x70, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x17, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x90, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x04, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 
	0x1d, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 
	0xd0, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
	0x03, 0x00, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 0xe0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x2b, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 
	0xe0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x02, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0xa0, 0x00, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0xac, 0x00, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 
	0xb0, 0x00, 0x00, 0x00, 0x06, 0x04, 0x00, 0x00, 0xbc, 0x00, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 
	0xd8, 0x00, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0xec, 0x00, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 
	0x04, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x1c, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 
	0x30, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x38, 0x01, 0x00, 0x00, 0x05, 0x04, 0x00, 0x00, 
	0x3c, 0x01, 0x00, 0x00, 0x06, 0x04, 0x00, 0x00, 0x44, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 
	0x54, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x6c, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 
	0x80, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x88, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 
	0xfc, 0x01, 0x00, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x02, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x07, 0x00, 0x00
};

int ExecIOP ( int argc, char* argv ) {

 int lRes;

 SifExecModuleBuffer (
  s_ExecIOP, sizeof ( s_ExecIOP ), argc, argv, &lRes
 );

 return lRes;

}  /* end ExecIOP */

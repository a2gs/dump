#ifndef __A2GS_TOOLBOX_DUMP_H__
#define __A2GS_TOOLBOX_DUMP_H__


/* *** INCLUDES *** */
	#include <stdio.h>


/* *** DEFINES *** */
	#define A2GS_TOOLBOX_DUMP_OK 1
	#define A2GS_TOOLBOX_DUMP_ERRO 0


/* *** DATA TYPES *** */


/* *** INTERFACES / PROTOTYPES *** */
	/* int  a2gs_ToolBox_DumpBuffer(void *data, size_t dataLen, unsigned char **bufOut)
	 *
	 * Assemply a buffer (malloc'ed()) witch the dump of buffer data.
	 * The user must free() the bufOut.
	 *
	 * INPUT:
	 *  data - Data to dump.
	 *  dataLen - Size os data (number of bytes to dump).
	 * OUTPUT:
	 *  bufOut - Address of a pointer that will receive a malloc'ed() memory.
	 *  A2GS_TOOLBOX_DUMP_ERRO - Erro when dumping.
	 *  A2GS_TOOLBOX_DUMP_OK - Dump Ok.
	 */
	int  a2gs_ToolBox_DumpBuffer(void * , size_t , unsigned char ** );


#if 0 /* EXAMPLE */
int main(){
   unsigned char a[30]="0123456789", *x = 0;
   int ret = 0;

   ret = a2gs_ToolBox_DumpBuffer(a, 5, &x) ;

   printf("\n%s %d\n", x, ret);

   free(x);

   return (1);
}
#endif

#endif

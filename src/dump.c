/*
 * Andre Augusto Giannotti Scota Tool Box Library.
 *
 * Public Domain.
 *
 */


/*
 * dump.c
 * This file implement the dump buffer function.
 *
 *
 *  Who     | When       | What
 *  --------+------------+----------------------------
 *   a2gs   | 2005 06 30 | Creation v0.1
 */


/* *** INCLUDES *** */
	#include <stdio.h>
	#include <string.h>
	#include <ctype.h>
	#include <stdlib.h>
	#include <dump.h>


/* *** DEFINES AND LOCAL DATA TYPE DEFINATION *** */
	#define A2GS_TOOLBOX_DUMPBUFFER_MAX_BYTES_PER_LINE 16
	#define A2GS_TOOLBOX_DUMPBUFFER_ONE_LINE_SIZE sizeof("xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx-aaaaaaaaaaaaaaaaN")
	#define A2GS_TOOLBOX_DUMPBUFFER_HEX_LINE_SIZE sizeof("xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx xx")


/* *** LOCAL PROTOTYPES *** */


/* *** EXTERNS / LOCAL GLOBALS *** */


/* ------------------------------------------------------------------------------------------- */


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
int a2gs_ToolBox_DumpBuffer(void *data, size_t dataLen, unsigned char **bufOut)
{
	unsigned char *bufOutWalker;
	size_t bufOutLen;
	unsigned char *bufInWalker;
	char auxFmt[3];
	unsigned int newLine, totalLines;
	unsigned char *hexCode, *asciiCode;

	bufInWalker = (unsigned char *)data;
	totalLines = (int)(dataLen / A2GS_TOOLBOX_DUMPBUFFER_MAX_BYTES_PER_LINE) + 1;
	bufOutLen = totalLines * A2GS_TOOLBOX_DUMPBUFFER_ONE_LINE_SIZE;

	if(((*bufOut) = (unsigned char *)malloc(bufOutLen)) == NULL)
		return(A2GS_TOOLBOX_DUMP_ERRO);

	bufOutWalker = (*bufOut);

	memset(*bufOut, 0, bufOutLen);

	for(newLine = 0; bufInWalker - (unsigned char *)data < dataLen; bufInWalker++, newLine++){
		auxFmt[0] = '\0';
		auxFmt[1] = '\0';
		auxFmt[2] = '\0';

		if(newLine == A2GS_TOOLBOX_DUMPBUFFER_MAX_BYTES_PER_LINE){
			*bufOutWalker = '\n';
			bufOutWalker++;
			newLine = 0;
		}

		if(newLine == 0){
			memset(bufOutWalker, ' ', A2GS_TOOLBOX_DUMPBUFFER_ONE_LINE_SIZE);
			hexCode = bufOutWalker;
			asciiCode = bufOutWalker + A2GS_TOOLBOX_DUMPBUFFER_HEX_LINE_SIZE - 1;
			*asciiCode = '-';
			asciiCode++;
		}

		snprintf(auxFmt, 3, "%02X", *bufInWalker);
		memcpy(hexCode, auxFmt, 2);

		(*asciiCode) = isprint(*bufInWalker) ? *bufInWalker : '.';

		hexCode += 3;
		asciiCode += 1;

		bufOutWalker = asciiCode;

	}
	*bufOutWalker = '\0';

	return(A2GS_TOOLBOX_DUMP_OK);
}

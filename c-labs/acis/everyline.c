// everyline.[ch] module:
//	Provided I/O support functions, most notably one to read every line
//	of a file and invoke a callback with that line.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "everyline.h"


// int n = foreveryline( filename, eachlinef );
//	open the given filename, read every line from that a file,
//	remove the trailing newline (if present) and invoke the given
//	callback eachlinef with the filename, the line number and the line.
//	Return the number of lines read, -1 if the file can't be opened.
//
int foreveryline( char *filename, everylinecb eachlinef )
{
	// TASK 1: IMPLEMENT THIS
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		return -1;
	}

	line buffer;
	size_t line_number = 0;
	while (fgets(buffer, MAXLINELEN, fp) != NULL) {
		line_number++;
		size_t len = strnlen(buffer, MAXLINELEN); 
		if (buffer[len - 1] == '\n') {
			buffer[len - 1] = '\0';
		}
		eachlinef(filename, line_number, buffer);
	}
	
	fclose(fp);
	return line_number;
}

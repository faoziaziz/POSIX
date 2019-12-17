#ifndef __errors_h
#define __errors_h

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  Define macro that can be used for diagnostic output form example
*/

#ifdef DEBUG
#define DPRINTF(arg) printf arg
#else
#define DPRINTF(arg)
#endif


#define err_abort(code, text) do {\
  fprintf(stderr, "%s at \"%s \":%d: %s \n", \
	  text, __FILE__, __LINE__, strerror(code));\
  abort();\
  } while(0)
#define errno_abort(text) do{\
  fprintf(stderr, "%s at \"%s\":%d %s\n",\
	  text, __FILE__, __LINE__, strerror(errno));\
  abort();\
  }while(0)
#endif




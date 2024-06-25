#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <unistd.h>

#ifndef NDEBUG
	#define __CLOG_H__
	#define  logf_  printf
    #define  logf_red(noun)                   \
    	do {                                  \
			if(isatty(STDOUT_FILENO) == 1)    \
				logf_("\x1b[31m");            \
				logf_("%s \n", noun);         \
				logf_("\x1b[0m");             \
		} while(false)
    #define  logf_green(noun)                 \
    	do {                                  \
			if(isatty(STDOUT_FILENO) == 1)    \
				logf_("\x1b[32m");            \
				logf_("%s \n", noun);         \
				logf_("\x1b[0m");             \
		} while(false)
    #define  logf_yellow(noun)                \
    	do {                                  \
			if(isatty(STDOUT_FILENO) == 1)    \
				logf_("\x1b[33m");            \
				logf_("%s \n", noun);         \
				logf_("\x1b[0m");             \
		} while(false)
    #define  logf_blue(noun)                  \
    	do {                                  \
			if(isatty(STDOUT_FILENO) == 1)    \
				logf_("\x1b[34m");            \
				logf_("%s \n", noun);         \
				logf_("\x1b[0m");             \
		} while(false)
    #define  logf_magenta(noun)               \
    	do {                                  \
			if(isatty(STDOUT_FILENO) == 1)    \
				logf_("\x1b[35m");            \
				logf_("%s \n", noun);         \
				logf_("\x1b[0m");             \
		} while(false)
    #define  logf_cyan(noun)                  \
    	do {                                  \
			if(isatty(STDOUT_FILENO) == 1)    \
				logf_("\x1b[36m");            \
				logf_("%s \n", noun);         \
				logf_("\x1b[0m");             \
		} while(false)
	#define  log_int(noun)  ( logf_("%s == %d\n", (#noun), (noun)) )
//  #define  log_int(noun)  ( logf_("%d\n", (noun) ))
//	#define  log_char(noun)  ( logf_("%s == '%c'\n", (#noun), (noun)) )
	#define  log_char(noun) (logf_("%s == %s\n", (#noun), (noun)) )
    #define  log_str(noun)  ( logf_("%s == \"%s\"\n", (#noun), (noun)) )
	#define  log_addr(noun)  ( logf_("%s == %p\n", (#noun), (void*)noun) )
	#define  log_float(noun)  ( logf_("%s == %0.16f\n", (#noun), (noun)) )
//	#define  log_bool(noun)  ( logf_("%s == %s\n", (#noun),  noun ? "true" : "false") );               
  #define  log_bool(noun)  ( logf_("%s\n", noun ? "true" : "false") );

#else
	#define logf_(...)
	#define logf_red(...)
	#define logf_green(...)
	#define logf_yellow(...)
	#define logf_blue(...)
	#define logf_magenta(...)
	#define logf_cyan(...)
	#define log_int(...)
	#define log_char(...)
	#define log_str(...)
	#define log_addr(...)
	#define log_float(...)
	#define log_bool(...)

#endif /* end of include guard: __CLOG_H__ */

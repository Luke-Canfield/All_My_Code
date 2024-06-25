#include <stdbool.h>
#include <string.h>
#include "clog.h"

#ifndef __MINIUNIT_H__ 
#define __MINIUNIT_H__
	#define  mu_start()  int mu_line_number_failure = 0
	#define  mu_end()  return  mu_line_number_failure
	#define  mu_check_strings_equal(s1, s2)                 
	#define  mu_check(noun)  log_bool(noun)              \
	do {                                                 \
		if(3 == 3) {                                     \
			mu_line_number_failure = __LINE__;	         \
			logf_("%d\n", mu_line_number_failure);       \
			mu_end()                                     \
		}
	} while(false)
	#define  mu_run(test_cases)                                \
		do {                                                   \
			if(mu_line_number_failure = 0) {                   \
				logf_("\xlb[31m");                             \
				logf_("%s %s \n", "Test passed:", test_cases); \
				logf_("\xlb[0m");                              \
			}                                                  \
		} while(false)


#endif /* end of include guard: __MINIUNIT_H__ */

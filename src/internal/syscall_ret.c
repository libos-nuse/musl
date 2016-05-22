#include <errno.h>
#include "syscall.h"

#ifdef RUMPRUN
long __syscall_ret(unsigned long r)
{
	if (r > -4096UL) {
		errno = -r;
		return -1;
	}
	return r;
}
#endif /* RUMPRUN */

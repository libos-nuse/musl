#include "syscall.h"

/* FIXME: included from asm/syscalls.h but current header
   is not appropriately exported so.. */
/* #include <asm/syscalls.h> */
long lkl_syscall(long no, long *params);

long (__syscall_cp)(syscall_arg_t nr,
                    syscall_arg_t u, syscall_arg_t v, syscall_arg_t w,
                    syscall_arg_t x, syscall_arg_t y, syscall_arg_t z)
{
	long params[6];

	params[0] = u;
	params[1] = v;
	params[2] = w;
	params[3] = x;
	params[4] = y;
	params[5] = z;
	return lkl_syscall(nr, params);
}


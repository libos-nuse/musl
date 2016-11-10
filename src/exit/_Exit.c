#include <stdlib.h>
#include "syscall.h"

#if defined(RUMPRUN) || !defined(CONFIG_LKL)
_Noreturn void _Exit(int ec)
{
	__syscall(SYS_exit_group, ec);
	for (;;) __syscall(SYS_exit, ec);
}
#endif /* RUMPRUN */

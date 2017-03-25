#include <stdlib.h>
#include "syscall.h"

#ifdef CONFIG_LKL
void _Noreturn _exit(int);
_Noreturn void _Exit(int ec)
{
	_exit(ec);
}
#else
_Noreturn void _Exit(int ec)
{
	__syscall(SYS_exit_group, ec);
	for (;;) __syscall(SYS_exit, ec);
}
#endif /* CONFIG_LKL */

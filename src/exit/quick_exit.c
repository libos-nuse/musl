#include <stdlib.h>
#include "libc.h"

static void dummy() { }
void __funcs_on_quick_exit();
weak_alias0(dummy, __funcs_on_quick_exit);

_Noreturn void quick_exit(int code)
{
	__funcs_on_quick_exit();
	_Exit(code);
}

#include "pthread_impl.h"
#include "libc.h"

static void dummy()
{
}

weak_alias0(dummy, __testcancel);

void __pthread_testcancel()
{
	__testcancel();
}

weak_alias(__pthread_testcancel, pthread_testcancel);

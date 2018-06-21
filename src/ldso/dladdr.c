#define _GNU_SOURCE
#include <dlfcn.h>
#include "libc.h"

int stub_dladdr(const void *addr, Dl_info *info)
{
	return 0;
}

weak_alias(stub_dladdr, dladdr);

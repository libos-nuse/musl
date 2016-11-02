#include <sys/mman.h>

int __mprotect(void *addr, size_t len, int prot)
{
	return mprotect(addr, len, prot);
}


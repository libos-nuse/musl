#include <sys/mman.h>

void *__mmap(void *start, size_t len, int prot, int flags, int fd, off_t off)
{
	/* call franken's mmap stub */
	return mmap(start, len, prot, flags, fd, off);
}

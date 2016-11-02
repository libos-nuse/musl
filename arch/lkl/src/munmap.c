#include <sys/mman.h>

int __munmap(void *start, size_t len)
{
	/* call franken's munmap stub */
	return munmap(start, len);
}

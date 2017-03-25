#include "pthread_impl.h"

void	*bmk_sched_tls_alloc(void);

int __set_thread_area(void *p)
{
//	p = bmk_sched_tls_alloc();
	return 0;

#ifdef SYS_set_thread_area
	return __syscall(SYS_set_thread_area, p);
#else
	return -ENOSYS;
#endif
}

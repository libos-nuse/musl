#include "pthread_impl.h"

int  rumpuser_thread_create(void *(*f)(void *), void *, const char *, int,
			    int, int, void **);

int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
{
	int ret;
	void *tid;
	struct pthread *self = arg;

	ret = rumpuser_thread_create((void *(*)(void *))func, self,
				     "__clone", 0, 0, -1, &tid);

	self->tid = *(int *)tid;
	return ret;
}

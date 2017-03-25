#include "pthread_impl.h"

struct bmk_thread *bmk_sched_create_withtls(const char *, void *, int,
				    void (*)(void *), void *,
				    void *, unsigned long, void *);

int __clone(int (*func)(void *), void *stack, int flags, void *arg, ...)
{
	int ret;
	void *tid;
	struct pthread *self = arg;

	tid = bmk_sched_create_withtls("__clone", NULL, 1,
				       (void (*)(void *))func, self,
				       stack, self->stack_size, self);


	self->tid = (uintptr_t)tid;
	return ret;
}

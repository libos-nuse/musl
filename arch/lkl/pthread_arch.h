#include "libc.h"

void *rumprun_thread_gettcb(void);
extern pthread_t main_td;

static inline struct pthread *__pthread_self()
{
	struct pthread *self;

	if (!libc.threaded)
		return main_td;

	self = (struct pthread *)rumprun_thread_gettcb();
	return self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]

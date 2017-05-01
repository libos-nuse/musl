#include "libc.h"

void *rumprun_thread_gettcb(void);
extern pthread_t main_td;

static inline struct pthread *__pthread_self()
{
	struct pthread *self;

#ifdef RUMPRUN
	if (!libc.threaded)
#endif	/* RUMPRUN */
		return main_td;

	self = (struct pthread *)rumprun_thread_gettcb();
	return self;
}

#define TP_ADJ(p) (p)

#ifdef __x86_64__
#define MC_PC gregs[REG_RIP]
#elif __arm__
#define MC_PC arm_pc
#endif

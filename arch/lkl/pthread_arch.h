void *rumpuser_thread_get_cookie(void);

static inline struct pthread *__pthread_self()
{
	struct pthread *self;
	self = (struct pthread *)rumpuser_thread_get_cookie();
	return self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]

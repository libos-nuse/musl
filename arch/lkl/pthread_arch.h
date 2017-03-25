void	*bmk_sched_gettcb(void);

static inline struct pthread *__pthread_self()
{
	struct pthread *self;
	self = bmk_sched_gettcb();
	return self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]

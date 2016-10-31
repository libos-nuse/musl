extern const struct __locale_struct __c_locale;

static inline struct pthread *__pthread_self()
{
	struct pthread *self;
	__asm__ __volatile__ ("mov %%fs:0,%0" : "=r" (self) );
#ifdef CONFIG_LKL             /* FIXME */
	self->locale = (locale_t)&__c_locale;
#endif
	return self;
}

#define TP_ADJ(p) (p)

#define MC_PC gregs[REG_RIP]

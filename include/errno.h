#ifndef	_ERRNO_H
#define _ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <features.h>

#include <bits/errno.h>

#ifdef CONFIG_LKL
int *__errno(void);
#define errno (*__errno())
#else  /* !CONFIG_LKL */
int *__errno_location(void);
#define errno (*__errno_location())
#endif	/* CONFIG_LKL */

#ifdef _GNU_SOURCE
extern char *program_invocation_short_name, *program_invocation_name;
#endif

#ifdef __cplusplus
}
#endif

#endif


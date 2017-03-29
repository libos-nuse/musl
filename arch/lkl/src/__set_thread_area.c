#include "pthread_impl.h"

pthread_t main_td;

int __set_thread_area(void *p)
{
	main_td = p;
	return 0;
}

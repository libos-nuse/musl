void __synccall(void (*func)(void *), void *ctx)
{
	func(ctx);
}

.text
.global ___cp_begin
.global ___cp_end
.global ___cp_cancel
.global ___syscall_cp_asm
___syscall_cp_asm:

___cp_begin:
	mov (%rdi),%eax
	test %eax,%eax
	jnz ___cp_cancel
	mov %rdi,%r11
	mov %rsi,%rax
	mov %rdx,%rdi
	mov %rcx,%rsi
	mov %r8,%rdx
	mov %r9,%r10
	mov 8(%rsp),%r8
	mov 16(%rsp),%r9
	mov %r11,8(%rsp)
	syscall
___cp_end:
	ret
___cp_cancel:
	jmp ___cancel

sys_call_id = 0x80
exit_syscall = 0x1

.data
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	$10,%eax
		pushl	%eax
		movl	$20,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,intb0
		movl	$5,%eax
		movl	%eax,intc1
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
		addl	$8,%esp
		leave
		ret

.global _start
_start:
		call _main
		movl $0,%ebx
		movl $exit_syscall,%eax
		int $sys_call_id

#bss section
		.comm	intb0,4,4
		.comm	intc1,4,4

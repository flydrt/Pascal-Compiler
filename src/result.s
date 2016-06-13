sys_call_id = 0x80
exit_syscall = 0x1

.data


# test11 function
.text
.global test11
		.type	test11,@function
test11:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	$1,%eax
		movl	%eax,c2
		movl	16(%ebp),%eax
		pushl	%eax
		movl	12(%ebp),%eax
		popl	%edx
		addl	%edx,%eax
		pushl	%eax
		movl	c2,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,16(%ebp)
		movl	%eax,-4(%ebp)
		leave
		ret
# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	$10,%eax
		movl	%eax,a8
		movl	$10,%eax
		movl	%eax,b9
		movl	a8,%eax
		pushl	%eax
		movl	b9,%eax
		pushl	%eax
		pushl	%ebp
		call	test11
		addl	$8,%esp
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
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
		.comm	c2,4,4
		.comm	a8,4,4
		.comm	b9,4,4

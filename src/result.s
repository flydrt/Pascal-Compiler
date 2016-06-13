sys_call_id = 0x80
exit_syscall = 0x1

.data


# test10 function
.text
.global test10
		.type	test10,@function
test10:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	16(%ebp),%eax
		pushl	%eax
		movl	12(%ebp),%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,16(%ebp)
		movl	16(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
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
		movl	%eax,a7
		movl	$10,%eax
		movl	%eax,b8
		movl	a7,%eax
		pushl	%eax
		movl	b8,%eax
		pushl	%eax
		pushl	%ebp
		call	test10
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
		.comm	a7,4,4
		.comm	b8,4,4

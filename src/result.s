sys_call_id = 0x80
exit_syscall = 0x1

.data


# inner12 function
.text
.global inner12
		.type	inner12,@function
inner12:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	d10,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		leave
		ret
# test18 function
.text
.global test18
		.type	test18,@function
test18:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	$117,%eax
		movl	%eax,d10
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,12(%ebp)
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	inner12
		addl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$2,%eax
		popl	%edx
		imul	%edx,%eax
		movl	%eax,12(%ebp)
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	inner12
		addl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$2,%eax
		movl	%eax,%ecx
		popl	%eax
		subl	%edx,%edx
		idiv	%ecx
		movl	%eax,12(%ebp)
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	inner12
		addl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$2,%eax
		popl	%edx
		subl	%eax,%edx
		movl	%edx,%eax
		movl	%eax,12(%ebp)
		movl	12(%ebp),%eax
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
		movl	%eax,a16
		movl	a16,%eax
		pushl	%eax
		pushl	%ebp
		call	test18
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
		.comm	d10,4,4
		.comm	a16,4,4

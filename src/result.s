sys_call_id = 0x80
exit_syscall = 0x1

.data


# test16 function
.text
.global test16
		.type	test16,@function
test16:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$0,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jg	j_LABEL2
		xorl	%eax,%eax
j_LABEL2:
		cmpl	$1,%eax
		jl	if_else_LABEL0
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	12(%ebp),%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		subl	%eax,%edx
		movl	%edx,%eax
		movl	%eax,12(%ebp)
		movl	12(%ebp),%eax
		pushl	%eax
		pushl	%ebp
		call	test16
		addl	$8,%esp
		movl	%eax,a0
		jmp	if_exit_LABEL1
if_else_LABEL0:
		movl	%eax,-4(%ebp)
if_exit_LABEL1:
		leave
		ret
# outer15 function
.text
.global outer15
		.type	outer15,@function
outer15:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		leal	a6,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
		movl	a6,%eax
		pushl	%eax
		movl	12(%ebp),%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,a6
		movl	a6,%eax
		pushl	%eax
		pushl	%ebp
		call	test16
		addl	$8,%esp
		movl	%eax,a6
		leave
		ret
# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	$1,%eax
		movl	%eax,a13
		movl	a13,%eax
		pushl	%eax
		pushl	%ebp
		call	outer15
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
		.comm	a0,4,4
		.comm	a6,4,4
		.comm	a13,4,4

sys_call_id = 0x80
exit_syscall = 0x1

.data


# test12 function
.text
.global test12
		.type	test12,@function
test12:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	$1,%eax
		movl	%eax,a0
while_start_LABEL0:
		movl	a0,%eax
		pushl	%eax
		movl	$10,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jle	j_LABEL2
		xorl	%eax,%eax
j_LABEL2:
		cmpl	$1,%eax
		jl	while_end_LABEL1
		movl	12(%ebp),%eax
		pushl	%eax
		movl	a0,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	a0,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		addl	%edx,%eax
		movl	%eax,a0
		jmp	while_start_LABEL0
while_end_LABEL1:
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
		movl	%eax,b9
for_start_LABEL3:
		movl	b9,%eax
		pushl	%eax
		movl	$10,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		jle	j_LABEL4
		xorl	%eax,%eax
j_LABEL4:
		cmpl	$1,%eax
		jl	for_end_LABEL5
		leal	a8,%eax
		pushl	%eax
		movl	b9,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		movl	b9,%eax
		popl	%ebx
		movl	%eax,(%ebx)
		incl	b9
		jmp	for_start_LABEL3
for_end_LABEL5:
		leal	a8,%eax
		pushl	%eax
		pushl	%ebp
		call	test12
		addl	$8,%esp
		movl	$10,%eax
		movl	%eax,b9
repeat_LABEL6:
		leal	a8,%eax
		pushl	%eax
		movl	b9,%eax
		subl	$1,%eax
		movl	$4,%ecx
		imul	%ecx
		popl	%edx
		addl	%eax,%edx
		pushl	%edx
		popl	%ebx
		movl	(%ebx),%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	b9,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		subl	%eax,%edx
		movl	%edx,%eax
		movl	%eax,b9
		movl	b9,%eax
		pushl	%eax
		movl	$0,%eax
		popl	%edx
		cmpl	%eax,%edx
		movl	$1,%eax
		je	j_LABEL7
		xorl	%eax,%eax
j_LABEL7:
		cmpl	$0,%eax
		je	repeat_LABEL6
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
		.comm	b9,4,4
		.comm	a8,40,4

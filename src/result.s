sys_call_id = 0x80
exit_syscall = 0x1

.data

.globl str_0
		.section .rodata
		.align 4
.LCstr_0:
		.string "The a of outer: "
		.data
		.align 4
		.type str_0 @object
str_0:
		.long .LCstr_0
.globl str_1
		.section .rodata
		.align 4
.LCstr_1:
		.string "Input a : "
		.data
		.align 4
		.type str_1 @object
str_1:
		.long .LCstr_1

# test34 function
.text
.global test34
		.type	test34,@function
test34:
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
		call	test34
		addl	$8,%esp
		movl	%eax,a0
		jmp	if_exit_LABEL1
if_else_LABEL0:
		movl	a0,%eax
		movl	%eax,-4(%ebp)
if_exit_LABEL1:
		leave
		ret
# outer32 function
.text
.global outer32
		.type	outer32,@function
outer32:
		pushl	%ebp
		movl	%esp,%ebp
		subl	$8,%esp
		movl	16(%ebp),%eax
		pushl	%eax
		movl	12(%ebp),%eax
		popl	%edx
		imul	%edx,%eax
		movl	%eax,a12
		movl	str_0,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		movl	a12,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
		movl	a12,%eax
		pushl	%eax
		pushl	%ebp
		call	test34
		addl	$8,%esp
		movl	%eax,a12
		leave
		ret
# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	str_1,%eax
		pushl	%eax
		pushl	%ebp
		call	_write_string
		addl	$8,%esp
		leal	a26,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
		movl	$0,%eax
		movl	%eax,b27
		movl	a26,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL3
		movl	$0,%eax
		movl	%eax,b27
case_LABEL3:
		movl	$2,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL4
		movl	$1,%eax
		movl	%eax,b27
case_LABEL4:
		movl	$3,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL5
		movl	$2,%eax
		movl	%eax,b27
case_LABEL5:
		movl	b27,%eax
		pushl	%eax
		movl	$0,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL6
		movl	$5,%eax
		movl	%eax,c28
case_LABEL6:
		movl	$2,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL7
		movl	$6,%eax
		movl	%eax,c28
case_LABEL7:
		movl	$1,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL8
		movl	$7,%eax
		movl	%eax,c28
case_LABEL8:
		movl	a26,%eax
		pushl	%eax
		movl	c28,%eax
		pushl	%eax
		pushl	%ebp
		call	outer32
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
		.comm	a12,4,4
		.comm	a26,4,4
		.comm	b27,4,4
		.comm	c28,4,4

sys_call_id = 0x80
exit_syscall = 0x1

.data

.globl str_0
		.section .rodata
		.align 4
.LCstr_0:
		.string "red"
		.data
		.align 4
		.type str_0 @object
str_0:
		.long .LCstr_0

# main routine
.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		leal	b1,%eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8,%esp
		movl	b1,%eax
		pushl	%eax
		movl	$1,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL0
		movl	$0,%eax
case_LABEL0:
		movl	$2,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL1
		movl	$1,%eax
case_LABEL1:
		movl	$3,%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL2
		movl	$2,%eax
case_LABEL2:
		movl	$0,%eax
		pushl	%eax
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL3
		movl	str_0,%eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
		addl	$8,%esp
case_LABEL3:
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL4
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
case_LABEL4:
		popl	%edx
		cmpl	%edx,%eax
		pushl	%edx
		jne	case_LABEL5
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8,%esp
case_LABEL5:
		leave
		ret

.global _start
_start:
		call _main
		movl $0,%ebx
		movl $exit_syscall,%eax
		int $sys_call_id

#bss section
		.comm	b1,4,4
		.comm	red2,4,4
		.comm	green6,4,4
		.comm	yellow5,4,4

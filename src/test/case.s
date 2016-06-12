sys_call_id = 0x80
exit_syscall = 0x1

.data
.globl cz_003
		.section .rodata
		.align 4
.LCcz_003:
		.string "it is 3"
		.data
		.align 4
		.type cz_003 @object
		.size cz_003, 4
cz_003:
		.long .LCcz_003
.globl cz_002
		.section .rodata
		.align 4
.LCcz_002:
		.string "it is 2"
		.data
		.align 4
		.type cz_002 @object
		.size cz_002, 4
cz_002:
		.long .LCcz_002
.globl cz_001
		.section .rodata
		.align 4
.LCcz_001:
		.string "it is 1"
		.data
		.align 4
		.type cz_001 @object
		.size cz_001, 4
cz_001:
		.long .LCcz_001


#---program helloworld ---

# --- main routine ----
		.text
.globl _main
		.type _main, @function
_main:
		pushl	%ebp
		movl	%esp, %ebp
		leal	va_001, %eax
		pushl	%eax
		pushl	%ebp
		call	_read_int
		addl	$8, %esp
		jmp switch_test_0
case_0_0:
		movl	cz_001, %eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
		addl	$8, %esp
		jmp switch_exit_0
case_0_1:
		movl	cz_002, %eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
		addl	$8, %esp
		jmp switch_exit_0
case_0_2:
		movl	cz_003, %eax
		pushl	%eax
		pushl	%ebp
		call	_writeln_string
		addl	$8, %esp
		jmp switch_exit_0
switch_test_0:
		movl	va_001, %eax
		pushl	%eax
		movl	$1, %eax
		popl	%edx
		cmpl	%eax, %edx
		movl	$1, %eax
		je	j_001
		xorl	%eax, %eax
j_001:
		cmpl	$1, %eax
		jge	case_0_0
		movl	va_001, %eax
		pushl	%eax
		movl	$2, %eax
		popl	%edx
		cmpl	%eax, %edx
		movl	$1, %eax
		je	j_002
		xorl	%eax, %eax
j_002:
		cmpl	$1, %eax
		jge	case_0_1
		movl	va_001, %eax
		pushl	%eax
		movl	$3, %eax
		popl	%edx
		cmpl	%eax, %edx
		movl	$1, %eax
		je	j_003
		xorl	%eax, %eax
j_003:
		cmpl	$1, %eax
		jge	case_0_2
switch_exit_0:
		leave
		ret


.globl _start
_start:
		call _main
		movl $0, %ebx
		movl $exit_syscall, %eax
		int  $sys_call_id
.ident	"SPL: 0.1.5"

#.bss variables
		.comm va_001,4,4

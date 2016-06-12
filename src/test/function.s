sys_call_id = 0x80
exit_syscall = 0x1

.data


#---program helloworld ---

# routine : test 
.text
.globl rtn001
		.type rtn001, @function
rtn001:
		pushl	%ebp
		movl	%esp, %ebp
		subl	$8, %esp
		subl	$0, %esp
		movl	12(%ebp), %eax
		pushl	%eax
		movl	$1, %eax
		popl	%edx
		addl	%edx, %eax
		pushl	%eax
		leal	12(%ebp), %eax
		pushl	%eax
		popl	%ebx
		popl	%eax
		movl	%eax, (%ebx)
		movl	12(%ebp), %eax
		movl	%eax, -4(%ebp)

		movl	-4(%ebp), %eax
		leave
		ret
		.size rtn001, .-rtn001


# --- main routine ----
		.text
.globl _main
		.type _main, @function
_main:
		pushl	%ebp
		movl	%esp, %ebp
		movl	$10, %eax
		movl	%eax, va_001
		movl	va_001, %eax
		pushl	%eax
		pushl	%ebp
		call	rtn001
		addl	$8, %esp
		pushl	%eax
		pushl	%ebp
		call	_writeln_int
		addl	$8, %esp
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

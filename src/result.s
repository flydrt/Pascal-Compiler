sys_call_id = 0x80
exit_syscall = 0x1

.text
.global _main
		.type _main,@function
_main:
		pushl	%ebp
		movl	%esp,%ebp
		movl	6.953216e-310dx,hello
		movl	6.953216e-310dx,hello
		leave
		ret

.global _start
_start:
		call _main
		movl $0,%ebx
		movl $exit_syscall,%eax
		int $sys_call_id

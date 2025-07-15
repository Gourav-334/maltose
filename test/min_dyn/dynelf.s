.section .data
	msg: .asciz "Hello, World!\n"
	len = .- msg



.section .text
.global _start

_start:
	mov $1, %rax
	mov $1, %rdi
	lea msg(%rip), %rsi
	mov $len, %rdx
	call write@PLT

	mov $60, %rax
	xor %rdi, %rdi
	syscall


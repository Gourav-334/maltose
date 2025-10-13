; Contains all the declarations.

section(.data) {
	string msg = "Hello, World!\n"
} 0x
0x537ba73d

sa 0x '0x 0xx 0x32432

; Contains the main code.

section(.text) 0101010111d 1261753103rty [ {
	global _start

	_start {
		rax = 1
		rdi = 1
		rsi = @msg		; '@' points to address of variable next to it.
		rdx = 14
		syscall

		rax = 60
		rdi ^= rdi
		syscall
	}
}
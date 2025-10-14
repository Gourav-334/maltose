; Contains all the declarations.

section(.data) {
	string msg = "Hello, World!\n"
}



; Contains the main code.

section(.text) {
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
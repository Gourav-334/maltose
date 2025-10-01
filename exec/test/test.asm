section(.data) {
	string msg = "Hello, World!\n"
}



section(.text) {
	global _start

	_start {
		rax = 1
		rdi = 1
		rsi = @msg
		rdi = 14
		syscall

		rax = 60
		rax ^= rax
		syscall
}

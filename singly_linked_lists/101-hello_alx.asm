global main
extern printf

section .data
	message db "Hello, Frontier", 10, 0

section .text
main:
	push rbp
	mov rbp, rsp
	lea rdi, [rel message]
	xor eax, eax
	call printf
	pop rbp
	ret

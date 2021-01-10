section .text ; TEXT section
global ft_strcpy ; Make ft_strcpy visible in global scope

ft_strcpy:
	push rbp ; A fixed phrase when calling a function
	mov rbp, rsp
	mov rax, rdi ; The value to be returned as the pointer of the first argument
	mov rbx, 0x0 ; A variable that holds what number you are looking at

loop_cpy:
	mov cl, BYTE [rsi + rbx] ; Copy the source value
	mov BYTE [rdi + rbx], cl ; Copy to copy destination
	cmp BYTE [rsi + rbx], 0x0 ; Whether the character you are currently looking at is a null character
	je finish_strcpy ; If they match, the process of termination
	inc rbx ; I recommend one place you are looking at
	jmp loop_cpy

finish_strcpy:
	leave ; A cliché at the end of a function
	ret

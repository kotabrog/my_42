section .text ; TEXT section
global ft_strcmp ; Make ft_strcmp visible in global scope

ft_strcmp:
	push rbp ; A fixed phrase when calling a function
	mov rbp, rsp
	mov rbx, 0x0 ; A variable that holds what number you are looking at
	mov ecx, 0x0 ; Initialization of the variable that copies the value of the second argument
	mov rax, 0x0 ; Initialization of return value
loop_cpy:
	mov cl, BYTE [rsi + rbx] ; Copy the value of the second argument
	cmp BYTE [rdi + rbx], cl ; Whether the characters you are currently looking at are equal
	jne finish_strcmp ; If they do not match, the process of termination
	cmp cl, 0x0 ; Whether the character you are currently looking at is a null character
	je finish_strcmp ; If it is a null character, it ends
	inc rbx ; I recommend one place you are looking at
	jmp loop_cpy
finish_strcmp:
	mov al, BYTE [rdi + rbx] ; Copy the value of the first argument to the return value
	sub eax, ecx ; Subtract the value of the second argument from the return value
	leave ; A cliché at the end of a function
	ret

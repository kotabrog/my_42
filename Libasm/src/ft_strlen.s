section .text ; TEXT section
global ft_strlen ; Make ft_strlen visible in global scope

ft_strlen:
	push rbp ; A fixed phrase when calling a function
	mov rbp, rsp
	mov rax, 0x0 ; Initialize the value to be returned to 0

loop_add:
	cmp BYTE [rdi + rax], 0x0 ; Whether the character you are currently looking at is a null character
	je finish_strlen ; If they match, the process of termination
	inc rax ; Advance the value by one
	jmp loop_add ; loop

finish_strlen:
	leave ; A cliché at the end of a function
	ret
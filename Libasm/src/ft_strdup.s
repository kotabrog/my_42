section .text ; TEXT section
global ft_strdup ; Make ft_strdup visible in global scope
extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup:
	push rbp ; A fixed phrase when calling a function
	mov rbp, rsp
	mov rbx, rdi ; Copy the first argument to rbx
	call ft_strlen ; Change the first argument len ​​to rax
	mov rdi, rax ; Len as the first argument
	inc rdi ; len + 1 for null
	call malloc wrt ..plt ; Get only len + 1
	cmp rax, 0x0 ; Compare eax values
	je set_error ; Enter a value for errno if rax is NULL
	mov rdi, rax ; copy this pointer to the first argument
	mov rsi, rbx ; Copy the copy source pointer to the second argument
	call ft_strcpy ; Copy the pointer reserved in rax
	jmp set_success ; Entering a value for errno on success

set_success:
	mov rbx, rax ; Temporarily save rax value in rbx
	call __errno_location wrt ..plt ; Assign the location of errno to rax
	mov DWORD [rax], 0x0 ; Stores the value of errno
	mov rax, rbx ; Restore the return value
	leave ; A cliché at the end of a function
	ret

set_error:
	mov ebx, eax ; Temporarily save eax value to ebx
	neg ebx ; Invert ebx
	call __errno_location wrt ..plt ; Change the location of errno to rax
	mov DWORD [rax], ebx ; Stores the value of errno
	mov rax, 0x0 ; Return value to NULL
	leave ; A cliché at the end of a function
	ret

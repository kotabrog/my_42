section .text ; TEXT section
global ft_write ; Make ft_write visible in global scope
extern __errno_location

ft_write:
	push rbp ; A fixed phrase when calling a function
	mov rbp, rsp
	mov rax, 1 ; write system call number
	syscall
	cmp eax, 0 ; Compare eax values
	jl set_error ; Enter a value in errno if eax is negative
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
	call __errno_location wrt ..plt ; Assign the location of errno to rax
	mov DWORD [rax], ebx ; Stores the value of errno
	mov rax, -1 ; Return value to -1
	leave ; A cliché at the end of a function
	ret

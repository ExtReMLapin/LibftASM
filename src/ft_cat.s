; syscall 0x2000003 read(int fd rdi, user_addr_t cbuf rsi , user_size_t nbyte rdx);
; syscall 0x2000004 write(int fd rdi, user_addr_t cbuf rsi , user_size_t nbyte rdx);

; ft_cat(int fd)

%define BUF_LEN		4096

section .bss
BUF:	resb BUF_LEN	; like a char buff[4096] ; i could also alloc it usign the mmap syscall

section .text
	global _ft_cat

_ft_cat:
	mov r12, rdi
	cmp rdi, 0
	jl .byebye

.loop:
	mov rdi, r12 ; restore RDI from R12 because if it's relooping, it was overwrote when using syscals
	lea rsi, [rel BUF]
	mov rdx, BUF_LEN
	mov rax, 0x2000003 ; calling read
	syscall ; read(rdi, rsi, rdx)
	jc .byebye
	js .byebye
	cmp rax, 0	; if read returned zero, we're at the end of the file, if it returned -1, it could not read the file descriptor
	jle .byebye

	mov rdi, 1		; fd = 1 is for console output
	lea rsi, [rel BUF]	; and we're readding from the buffer that read wrote in

	;read () -> RETURN VALUES
    ; If successful, the number of bytes actually read is returned.
	mov rdx, rax		;^^^^^^
	mov rax, 0x2000004 	; 
	syscall 			; write (1, [rel BUF], what read syscall returned)
	cmp rax, -1			; if it returned -1 then it failed
	je .byebye
	jmp .loop

.byebye:
	ret
	

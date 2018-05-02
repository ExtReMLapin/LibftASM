; syscall 0x2000003 read(int fd rdi, user_addr_t cbuf rsi , user_size_t nbyte rdx);
; syscall 0x2000004 write(int fd rdi, user_addr_t cbuf rsi , user_size_t nbyte rdx);

%define BUF_LEN		4096

section .bss
BUF:	resb BUF_LEN	; comme un char buff[4096] ; on pourait aussi l'allouer avec le syscall mmap

section .text
	global _ft_cat

_ft_cat:
	mov r12, rdi
	cmp rdi, 0
	jle .byebye

.loop:
	mov rdi, r12 ; on remet rdi comme il était psk il va etre overwrite apres
;; 	mov rsi, BUF	; meme prob que avec ft_puts, decalage de 1 byte donc segfault 
	lea rsi, [rel BUF]
	mov rdx, BUF_LEN
	mov rax, 0x2000003 ; call _read
	syscall ; read(rdi, rsi, rdx)
	jc .byebye
    js .byebye
	cmp rax, 0	; si on a zero alors on est à la fin, si on a -1, ca fail
	jle .byebye

	mov rdi, 1		; la sortie 1
	lea rsi, [rel BUF]	; et on pop le buffer danslequel on a ecris

	;read () RETURN VALUES
    ; If successful, the number of bytes actually read is returned.
	mov rdx, rax		;^^^^^^
	mov rax, 0x2000004 	; comme ft_puts quoi
	syscall 			; write (1, [rel BUF], ce qu'a return read)
	cmp rax, -1			; si ret -1 alors ca a fail
	je .byebye
	jmp .loop

.byebye:
	ret
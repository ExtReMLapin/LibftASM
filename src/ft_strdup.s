; char * ft_strdup(const char *rdi)

extern _strlen
extern _malloc
extern _memcpy

section .text
global _ft_strdup

_ft_strdup:
	enter 16, 0
	push rdi

	call _strlen		; passage implicite de rdi dans strlen, retouné dans rax
	mov rdi, rax	
	inc rdi				; on veut strlen(s) + 1 pour le \0
	push rdi
	call _malloc		; rax = malloc(strlen(rdi))
	
	cmp rax, 0			; if malloc fail then return NULL
	jz .ret

	mov rdi, rax		; should be the malloc adr
	pop rdx
	pop rsi
	call _memcpy

.ret:
	leave
	ret
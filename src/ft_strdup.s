; char * ft_strdup(const char *rdi)

section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	enter 16, 0
	push rdi

	call _ft_strlen		; passage implicite de rdi dans strlen, retouné dans rax
	mov rdi, rax	
	inc rdi				; on veut strlen(s) + 1 pour le \0
	push rdi
	call _malloc		; rax = malloc(strlen(rdi))

	cmp rax, 0			; if malloc fail then return NULL
	jz .ret

	mov rdi, rax		; should be the malloc adr
	pop rdx
	pop rsi
	call _ft_memcpy

.ret:
	leave
	ret
;size_t	strlen(const char *s);

section .text
	global _ft_strlen

_ft_strlen:
	mov rbx, rdi		; char *s should be rdi, rbx will be called s2

.loop:
	cmp byte [rbx], 0	; check if *s2 == '\0'
	je .end				; if yes then return
	inc rbx				; *(s2)++
	jmp .loop			; loop

.end:
	sub rbx, rdi		; s2 = s2 (which is greater than s) - s
	mov rax, rbx		; eax is the return value, right ?? and rbx is now the len
	ret
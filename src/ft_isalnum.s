section .text
	global _ft_isalnum

_ft_isalnum:
	cmp rdi, '0' ; avant 0 = fail
	jl .false
	cmp rdi, ':' ; avant 9 + 1 = success
	jl .true
	cmp rdi, 'A' ; etc
	jl .false
	cmp rdi, '['
	jl .true
	cmp rdi, 'a'
	jl .false
	cmp rdi, '{'
	jl .true
	jmp .false ; sinon, rip false gros

.true:
	mov rax, 1
	ret

.false:
	mov rax, 0
	ret

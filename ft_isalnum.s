section .text
	global _ft_isalnum

_ft_isalnum:
	cmp rdi, 48 ; avant 0 = fail
	jl .false
	cmp rdi, 58 ; avant 9 + 1 = success
	jl .true
	cmp rdi, 65; etc
	jl .false
	cmp rdi, 91
	jl, .true
	cmp rdi, 97
	jl .false
	cmp rdi, 123
	jl .true
	jmp .false ; sinon, rip false gros

.true:
	mov rax, rdi
	jmp .end

.false
	mov rax, 0
	jmp .end

.end
	ret

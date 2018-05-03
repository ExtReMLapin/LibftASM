; int ft_max(int rdi, int rsi)
section	.text
	global _ft_max

_ft_max:
	mov rax, 0
	cmp rdi, rsi
	jae .rdiset
	jb .rsiset
	ret

.rdiset
	mov rax, rdi
	ret

.rsiset
	mov rax, rsi
	ret
	
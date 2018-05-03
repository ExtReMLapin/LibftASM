; int ft_min(int rdi, int rsi)
section	.text
	global _ft_min

_ft_min:
	mov rax, 0
	cmp rdi, rsi
	jae .rsiset
	jb .rdiset
	ret

.rdiset:
	mov rax, rdi
	ret

.rsiset:
	mov rax, rsi
	ret
	
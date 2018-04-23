; char *strcat(char *restrict s1, const char *restrict s2);

;char	*ft_strcat(char *s1, const char *s2)
;{
;	int	i;
;	int	j;
;
;	i = 0;
;	j = 0;
;	while (s1[i] != '\0')
;		i++;
;	while (s2[j] != '\0')
;	{
;		s1[i] = s2[j];
;		j++;
;		i++;
;	}
;	s1[i] = '\0';
;	return (s1);
;} // on fout s2 au bout de s1

; using cl from rcx and not r8 cuz you dont want to overwrite any shit

section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	mov rax, 0	;i = 0
	mov rbx, 0	;j = 0

.lpstart:
	cmp byte[rdi+rax], 0 	; while (s1[i] != '\0') // comme un strlen de s1 quoi
	jz .lpmain 
	inc rax					; i++;
	jmp .lpstart

.lpmain:
	cmp byte[rsi+rbx], 0	; while (s2[j] != '\0')
	jz .end
	mov cl, [rsi+rbx]		; s1[i] = s2[j]; put  s2[j] into cl
	mov [rdi+rax], cl		; then cl in j1[i]
	inc rbx					; j++;
	inc rax					; i++;
	jmp .lpmain

.end:
	mov cl, 0				;	s1[i] = '\0';
	mov [rdi+rax], cl		
	mov rax, rdi			;	return (s1);
	ret
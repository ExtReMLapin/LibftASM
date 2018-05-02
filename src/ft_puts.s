
;int ft_puts( char* rdi)
; calling ssize_t write(int rdi, const void *rsi, size_t rdx);

; [write] syscall on macos :
;rsi = str
;rdi = 1 same as for the libc
;rdx = len of str
;rax =  0x2000004 (syscall of write)

%define EOF     -1

section .data
	NL:			db	012o	; new line
	NULLSTR:	db	"(null)"; bein ui

section .text
	global _ft_puts
	extern _ft_strlen2

_ft_puts:
	enter 16, 0
	cmp rdi, 0 			; checking is rdi is null
	je .null			; ;)
	push rdi			; backup rdi cuz we never know
	call _ft_strlen2

	;priting the string sent as parameter using libc
	;mov rdi, 1			
	;mov rdx, rax		; rdx = string length that was in parameter
	;pop rsi				; rsi = string that was in ft_puts parameter
	;call _write			; write(1, str, strlen(str))

	pop rsi
	mov rdi, 1
	mov rdx, rax
	mov rax, 0x2000004
	syscall
	cmp rax, EOF
	je .fail

	;now adding a \n at the end of the string
	mov rsi, NL			; rsi = string that was in ft_puts parameter
	mov rdi, 1			; sortie
	mov rdx, 1			; rdx = string length that was in parameter
	mov rax, 0x2000004
	syscall
	cmp rax, EOF
	je .fail

.success:
	mov rax, 10
	leave
	ret

.null:
	;priting the string sent as parameter
	lea rsi, [rel NULLSTR]	; rsi = string that was in ft_puts parameter
	mov rdi, 1			
	mov rdx, 6			; rdx = string length that was in parameter
	mov rax, 0x2000004
	syscall
	cmp rax, EOF
	je .fail

	;now adding a \n at the and of the string
	mov rsi, NL			; rsi = string that was in ft_puts parameter
	mov rdi, 1			; \n len = 1 , amirite ???
	mov rdx, 1			; rdx = string length that was in parameter
	mov rax, 0x2000004
	syscall
	cmp rax, EOF
	je .fail
	jmp .success

.fail:
	leave
	ret
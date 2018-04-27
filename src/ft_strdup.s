; char * ft_strdup(const char *rdi)

extern _strlen
extern _malloc
extern _memcpy

section .text
    global _ft_strdup

_ft_strdup:
	push rbp
	mov rbp, rsp
    push rdi

    mov r8, rdi                ; on save rdi dans r8
    call _strlen            ; passage implicite de rdi dans strlen, retouné dans rax
    mov rdi, rax    
    inc rdi                    ; on veut strlen(s) + 1 pour le \0
    mov r9, rdi
    push rdi
    call _malloc            ; rax = malloc(strlen(rdi))
    cmp rax, 0                ; if malloc fail then return NULL
    jz .ret

    mov rdi, rax            ; should be the malloc adr
    pop rdx
    pop rsi
    call _memcpy

.ret:
	mov rsp, rbp
	pop rbp
    ret
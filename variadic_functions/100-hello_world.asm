; 100-hello_world.asm
section .data
    msg db "Hello, World", 10 ; The message + newline
    len equ $ - msg          ; Calculate message length

section .text
    global _start

_start:
    mov rax, 1       ; syscall number for write
    mov rdi, 1       ; file descriptor 1 (stdout)
    mov rsi, msg     ; address of the string
    mov rdx, len     ; number of bytes
    syscall          ; make syscall

    mov rax, 60      ; syscall number for exit
    xor rdi, rdi     ; exit status 0
    syscall


; 100-hello_world.asm
section .data
    msg db "Hello, World", 10      ; The message followed by newline
    len equ $ - msg                ; Compute the length of the message

section .text
    global _start

_start:
    mov rax, 1         ; syscall: write
    mov rdi, 1         ; file descriptor: stdout
    mov rsi, msg       ; pointer to message
    mov rdx, len       ; message length
    syscall            ; invoke syscall

    mov rax, 60        ; syscall: exit
    xor rdi, rdi       ; status: 0
    syscall            ; invoke syscall


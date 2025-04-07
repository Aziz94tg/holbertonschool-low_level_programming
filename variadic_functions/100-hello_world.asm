section .data
    msg     db  "Hello, World", 10     ; The message + newline character
    msg_len equ $ - msg                ; Length of the message

section .text
    global _start

_start:
    mov rax, 1          ; syscall number for write (1)
    mov rdi, 1          ; file descriptor 1 = stdout
    mov rsi, msg        ; pointer to message
    mov rdx, msg_len    ; length of message
    syscall             ; invoke the system call

    mov rax, 60         ; syscall number for exit (60)
    xor rdi, rdi        ; status 0
    syscall             ; exit(0)


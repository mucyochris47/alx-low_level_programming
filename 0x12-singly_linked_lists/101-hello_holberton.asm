section .data
    hello db 'Hello, Holberton', 10  ; The string to print followed by a newline
    hello_len equ $ - hello           ; Length of the string

section .bss

section .text
    global _start

_start:
    ; Write the string to stdout
    mov rax, 1                      ; syscall number for sys_write
    mov rdi, 1                      ; file descriptor 1 is stdout
    mov rsi, hello                  ; pointer to the string
    mov rdx, hello_len              ; length of the string
    syscall                         ; invoke system call

    ; Exit the program
    mov rax, 60                     ; syscall number for sys_exit
    xor rdi, rdi                    ; exit code 0
    syscall                         ; invoke system call


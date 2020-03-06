# libasm

Write the following functions in x64 assembly (in the Intel syntax):
```
int		ft_strlen(char const *str);
int		ft_strcmp(char const *s1, char const *s2);
char		*ft_strcpy(char *dst, char const *src);
ssize_t		ft_write(int fd, void const *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(char const *s1);
```
#REGISTERS
```
; 64-bit [QWORD]
R8  R9  R10  R11  R12  R13  R14  R15
RAX RCX RDX RBX RSP RBP RSI RDI

; 32-bit [DWORD]
R8D R9D R10D R11D R12D R13D R14D R15D
EAX ECX EDX EBX ESP EBP ESI EDI

; 16-bit [WORD]
R8W R9W R10W R11W R12W R13W R14W R15W
AX  CX  DX  BX  SP  BP  SI  DI

; 8-bit [BYTE]
R8B R9B R10B R11B R12B R13B R14B R15B
AL  CL  DL  BL  SPL BPL SIL DIL

; 128-bit (used for floating point operations mostly)
XMM0 ... XMM15
```

# AS SYNTAX



## 1. Description


This directory lists the categories & sub-categories of overall **AS** syntax. For understanding relavancy, they are mapped with **AT&T** syntax.



## 2. Stepped Syntax Plan

1. Gather all the varying instructions & operands
2. Categorize them
3. Fill each category with unvisited syntaxes
4. Write all base-level possibilites for each instruction
5. Write all the rules & restrictions for each instruction



## 3. Elements Of Assembly


### 3.1 <u>Sorted instructions</u>:

```gas
.align 3
.ascii "String\n"
.asciz "String\n"
.byte '*'
.comm label, 5
.double 2.71828
.else
.endif
.endm
.endr
.equ MACRO, 64
.float 3.14
.global label
.globl label
.if MACRO == "value"
.ifdef MACRO
.ifndef MACRO
.longdouble 1.6180339887
.macro function p1, p2, res
.rept 9
.section .bss
.section .data
.section .stack
.section .text
.space 5
# Comment
add $op, label(%rip)
addp %xmm1, %xmm0
adds %xmm1, %xmm0
and %rax, %rbx
call label
cmp %rax, %rbx
cmpp $my_byte, %xmm1, %xmm0
comis %xmm1, %xmm0
dec %rax
div $op, %rax
divs %xmm1, %xmm0
divp %xmm1, %xmm0
fabs
fadd label
fchs
fcom label
fcomi label
fcomip label
fcomp label
fcompp label
fdiv label
fdivp label
fdivr label
fdivrp label
fld %st(n)
fld1
fldl2e
fldl2t
fldlg2
fldln2
fldpi
fldz
fmul label
fmulp label
fnstsw
fsqrt
fstsw %ax
fsub label
fsubp label
fsubr %st(n), %st(0)
fsubrp %st(n), %st(0)
fst %st(n)
fstp label
function $p1, $p2, $res
inc %rax
int $interrupt
ja label
jb label
je label
jg label
jl label
jle label
jmp label
jne label
jng label
jnge label
jnl label
jnle label
jnz label
jz label
label:
lea label(%rip), %rdi
length = .- string
mov $op, %rax
movap %xmm1, %xmm2
movs mem, %xmm0
movup %xmm1, %xmm3
mul $op, %rax
mulp %xmm1, %xmm0
muls %xmm1, %xmm0
neg %rax
not %rax
or %rax, %rbx
pand %xmm1, %xmm0
pandn %xmm1, %xmm0
pcmpeq $my_byte, %xmm1, %xmm0
pcmpgt $my_byte, %xmm1, %xmm0
pop %rbx
por %xmm1, %xmm0
push -4(%rax)
pxor %xmm1, %xmm0
ret
sal %rax
sar %rax
shl %rax
shr %rax
shufp $my_byte, %xmm1, %xmm0
sub $op, %rax
subp %xmm1, %xmm0
subs %xmm1, %xmm0
syscall
test $label, %rax
ucomis %xmm1, %xmm0
unpcklp %xmm1, %xmm0
unpckhp %xmm1, %xmm0
xor %rdi, %rdi
```

---
# COMPULSORY SYNTAX



## 1. Description


This file is dedicated to listing how the AS's x86 syntax relates to its corresponding AT&T x86 syntax. From section **2** onwards, different elements of compulsory assembly syntax are discussed.



## 2. Sections


### <u>AT&T</u>:

```gas
.section .<sec_name>
    # Section codes
```

- `<sec_name>` is name of the particular section.
- Section include `data`, `text`, `stack`, `bss`, etc.


### <u>AS</u>:

```asm
section(.<sec_name>) {
    ; Section codes
}
```



## 3. Types


### <u>AT&T</u>:

```gas
<label>: .<ascii_type> "value"    # ASCII label
<label>: .<size> <value>          # Numeric label

<label>: .<size> <val1> <val2> ... <valN>    # Table
```

- `<label>` is the name of label which is being defined.
- `<ascii_type>` is name of a particular ASCII type.
- ASCII type includes `ascii`, `asciz`/`string`, etc.
- `<size>` is the size for a defined numerical label.
- It could be `byte`, `word`, `long`, `quad`, `float`, `double`, `longdouble` etc.
- `<value>` is the value that is assigned to the label.
- `<val1>`, `<val2>`, etc upto `<valN>` are values of elements in table (array).


### <u>AS</u>:

```asm
<ascii_type> <label> = "value"    ; ASCII label
<size> <label> = <value>          ; Numeric label

<size> <label> = {<val1>, <val2>, ..., <valN>}    ; Table
```

- Here, the ASCII-related types are expected to be `ascii` & `string` (not its alias i.e. `asciz`).



## 4. Reserving Memory


### <u>AT&T</u>:

```gas
.comm <label>, <bytes>     # Method 1 (in bss)
<label>: .space <bytes>    # Method 2 (in bss)
```

- `<label>` is the label for reserved memory of `<bytes>` bytes.


### <u>AS</u>:

```asm
reserve <label>[<bytes>]    ; In bss section
```



## 5. Scope Information


### <u>AT&T</u>:

```gas
.code<bits>
.<scope> label
```

- `<bits>` tells for how many bits the assembler is running.
- It could be `16`, `32` or `64`.
- `<scope>` defines scope for a label.
- Scope includes `global`, `extern`, `local`, `weak`, `hidden`, `protected`, etc.


### <u>AS</u>:

```asm
mode <mode>
<scope> label
```

- `<mode>` is the name of mode.
- It could be `real`, `protected` or `long`.



## 6. Sub-Routines


### <u>AT&T</u>:

```gas
<sub_rout>:
    # Sub-routine codes
```

- `<sub_rout>` is the name given to sub-routine.


### <u>AS</u>:

```asm
<sub_rout> {
    ; Sub-routine codes
}
```



## 7. Macros


### <u>AT&T</u>:

```gas
.equ <macro>, <value>    # Symbolic constant (stiff)
.set <macro>, <value>    # Symbolic constant (changeable)
.align <power>           # Align memory
```

- `<macro>` is the name given to macro.
- `<value>` is the value assigned to macro.
- `<power>` aligns memory by $2^{<power>}$ bytes.


### <u>AS</u>:

```asm
rigid <macro> = <value>       ; Constant macro (stiff)
flexible <macro> = <value>    ; Constant macro (changeable)
align <power>                 ; Align memory
```



## 8. Movement/Overwritting


### <u>AT&T</u>:

```gas
<mne> $<const>, %<dest>    # Move value-to-register
<mne> %<src>, %<dest>      # Move register-to-register

<mne> $<const>, <label>+(<add>*<steps>)    # Table (val2reg)
<mne> %<src>, <label>+(<add>*<steps>)      # Table (reg2reg)
```

- `<mne>` is a mnemonic for any kind of movement opcode.
- It could be `mov`, etc.
- `<const>` is a source constant value.
- `<src>` is a register.
- `<dest>` is a register which is same as or different from register `<src>`.
- `<add>` is the address offset offset for the table.
- `<steps>` is number of steps to skip.


### <u>AS</u>:

```asm
<dest> = <const>    ; Move value-to-register
<dest> = <src>      ; Move register-to-register

<label>[<steps>] = <const>    ; Table (val2reg)
<label>[<steps>] = <src>      ; Table (reg2reg)
```



## 9. Arithmetic Operations


### <u>AT&T</u>:

```gas
<op> $<const>, %<dest>     # Value-to-register operation
<op> %<src>, %<dest>       # Register-to-register operation

f<op> %st(<n>), %st(0)     # Add ST(n) to ST(0)
f<op>p %st(<n>), %st(0)    # Add ST(n) to ST(0) & pop ST(n)
f<op>s <float>             # Add <float> to ST(0)
f<op>l <long>              # Add <long> to ST(0)
f<op>d <double>            # Add <double> to ST(0)
```

- `<op>` is arithmetic operator mnemonic.
- It could be `add`, `sub`, `mult`, `div`, etc.
- `<const>` is a source constant value.
- `<src>` is a register.
- `<dest>` is a register which is same as or different from register `<src>`.
- `<n>` is a index of a stack element.
- `<float>` is a float value.
- `<long>` is a long value.
- `<double>` is a long double value.


### <u>AS</u>:

```asm
<dest> <op_set>= <const>    ; Constant-to-register operation
<dest> <op_set>= <src>      ; Register-to-register operation

st(0) <op>= st(n)           ; Add ST(n) to ST(0)
st(0) <op>= popped st(n)       ; Add ST(n) to ST(0) & pop ST(n)
st(0) <op>= <float>         ; Add <float> to ST(0)
st(0) <op>= <long>          ; Add <long> to ST(0)
st(0) <op>= <double>        ; Add <double> to ST(0)
```

- `<op_set>` is the symbol for a particular *opcode set*.
- It could be `+`, `-`, `*`, `/`, etc.



## 10. Logical Operations


### <u>AT&T</u>:

```gas
<log> $<const>, %<dest>    # Constant-to-register operation
<log> %<src>, %<dest>      # Register-to-register operation
```

- `<log>` is mnemonic for any logical operation.
- It includes `and`, `or`, `not`, `xor`, etc.
- `<const>` is a source constant value.
- `<src>` is a GPR.
- `<dest>` is a GPR which is same as or different from GPR `<src>`.



### <u>AS</u>:

```asm
<dest> <sym>= <const>    ; Constant-to-register XOR
<dest> <sym>= <src>      ; Register-to-register XOR
```

- `<sym>` is symbolic representation of bitwise operation.
- It includes `&`, `|`, `~`, `^`, etc.



## 11. Bitwise Operations


### <u>AT&T</u>:

```gas
<bit> $<const>, %<dest>    # Value-to-register bitwise
<bit> %<src>, %<dest>      # Register-to-register bitwise
```

- `<bit>` is the mnemonic for bitwise operation.
- It could be `shl`/`sal`, `shr`/`sar`, etc.
- `<sym>` is the symbol for the operation.
- `<const>` is the constant operand for operation.
- `<src>` is the source operand for operation.


### <u>AS</u>:

```asm
<dest> <sym> <const>
<dest> <sym> <src>
```

- `<sym>` represents symbol that is required for each bitwise operation.
- It could be `<<`, `>>`, etc.



## 12. Copying Address


### <u>AT&T</u>:

```gas
lea <label>(%rip), %<dest>
```

- `<label>` represents the label whose address we want to copy.
- `<dest>` is the destination GPR register where address has to be moved.


### <u>AS</u>:

```asm
<dest> = @<label>
```



## 13. Special Operations


### <u>AT&T</u>:

```gas
inc %<gpr>                 # Increment GPR by 1
dec %<gpr>                 # Decrement GPR by 1
neg %<gpr>                 # Negate the GPR
cmp $<const>, %<gpr>       # Value-to-register comparison
cmp %<gpr1>, %<gpr2>       # Register-to-register comparison
xchg %<gpr1>, %<gpr2>      # Swap values of GPR1 & GPR2

nop                        # No operation (do nothing)
xlat                       # Look a byte in table using AL as its index

fxchg %st(<n>)             # Swap ST(0) & ST(n)
fsqrt                      # Replaces ST(0) with its sqrt
fabs                       # Replaces ST(0) with its abs value
fchs                       # Changes sign of ST(0)

fcom                       # Compare ST(0) with ST(1)
fcom %st(<n>)              # Compare ST(0) with ST(n)
fcom <value>               # Compare ST(0) with <value>
fcomp                      # Compare ST(0) with ST(1) & pop ST(0)
fcomp %st(<n>)             # Compare ST(0) with ST(i) & pop ST(0)
fcomp <value>              # Compare ST(0) with <value> & pop ST(0)
fcompp                     # Pops both ST(0) & ST(1)
fcomi %st(<n>), %st(0)     # Compares & sets CPU flags
fcomip %st(<n>), %st(0)    # Compares, pops & sets CPU flags
```

- `<gpr>` is a general purpose register.
- `<const>` is constant source.
- `<gpr1>` and `<gpr2>` are two general purpose registers.
- `<n>` is an index of any element in x87 FPU stack.
- `<value>` can be float, double or long double.


### <u>AS</u>:

```asm
<gpr>++                       ; Increment GPR by 1
<gpr>--                       ; Decrement GPR by 1
~<gpr>                        ; Negate the GPR
<gpr> ?= <const>              ; Value-to-register comparison
<gpr1> ?= <gpr2>              ; Register-to-register comparison
<gpr1> <-> <gpr2>             ; Swap values of GPR1 & GPR2

none                          ; No operation (do nothing)
al = <tbl>[al]                ; Look a byte in table using AL as its index

st(<n>) <-> st(0)             ; Swap ST(0) & ST(n)
sqrt st(0)                    ; Replaces ST(0) with its sqrt
|st(0)|                       ; Replaces ST(0) with its abs value

st(0) ?= st(n)                ; Compare ST(0) with ST(n)
st(0) ?= <value>              ;
st(0) ?= st(n).(pop)          ; Compare <value> with ST(n) & pop ST(n)
st(0) ?= st(n).(flag)         ; Compare & set CPU flag
st(0) ?= st(n).(pop, flag)    ; Combination of previous two lines
```

- `<tbl>` name of the table.



## 14. Call & Return


### <u>AT&T</u>:

```gas
call <label>    # Call sub-routine
ret             # Simply return
ret $<n>        # Pop 'n' elements
```

- `<label>` represents a label which we are trying to call or return from here.
- `<n>` is a constant.


### <u>AS</u>:

```asm
call <label>()    ; Call sub-routine
return            ; Return
return <n>        ; Return 'n' elements
```



## 15. Jumps


### <u>AT&T</u>:

```gas
jmp <label>     # Unconditional

je <label>      # Equal
jne <label>     # Not equal

jz <label>      # Zero
jnz <label>     # Not zero

jl <label>      # Less than
jnl <label>     # Not less than
jle <label>     # Less than or equal
jnle <label>    # Not less than or equal

jg <label>      # Greater than
jng <label>     # Not greater than
jge <label>     # Greater or equal
jnge <label>    # Not greater or equal
```

- `<label>` is the label where jump statements lead to.


### <u>AS</u>:

```asm
<label>()       ; Unconditional

<label>(=)      ; Equal
<label>(!=)     ; Not equal

<label>(0)      ; Zero
<label>(!0)     ; Not zero

<label>(<)      ; Less than
<label>(!<)     ; Not less than
<label>(<=)     ; Less than or equal
<label>(!<=)    ; Not less than or equal

<label>(>)      ; Greater than
<label>(!>)     ; Not greater than
<label>(>=)     ; Greater than or equal
<label>(!>=)    ; Not greater or equal
```



## 16. Stack-Based Operations


### <u>AT&T</u>:

```gas
push $<const>           # Push constant
push %<gpr>             # Push register
push -<byte>(%<gpr>)    # Push by referred address
pop                     # Simple popping
pop %<gpr>              # Pop to register

pushf                   # Save E/RFLAG to stack
popf                    # Load top stack element to E/RFLAG

fld %st(<n>)            # Re-push x87 stack's Nth element
flds <float>            # Push float to x87 stack
fldl <long>             # Push long to x87 stack
fldt <double>           # Push long double to x87 stack

fst %st(<n>)            # Store 0th element at Nth index
fsts <float>            # Store 0th element in <float>
fstl <long>             # Store 0th element in <long>
fstt <double>           # Store 0th element in <double>

fstp %st(<n>)           # Pop 0th element to Nth index
fstps <float>           # Pop 0th element to <float>
fstpl <long>            # Pop 0th element to <long>
fstpt <double>          # Pop 0th element to <double>
```

- `<const>` is a contant which is being pushed to stack.
- `<gpr>` is a general purpose register.
- `<byte>`, as used is how many bytes behind `<gpr>` the target value to be pushed is located.
- `<n>` is a index of a stack element.
- `<float>` is a float value.
- `<long>` is a long value.
- `<double>` is a long double value.


### <u>AS</u>:

```asm
push <const>         ; Push constant
push <gpr>           ; Push GPR
push <gpr>-<byte>    ; Push by referred address
pop                  ; Simple popping
pop <gpr>            ; Pop to register

push st(<n>)         ; Re-push x87 stack's Nth element
push <float>         ; Push float to x87 stack
push <long>          ; Push long to x87 stack
push <double>        ; Push long double to x87 stack

store st(<n>)        ; Store 0th element at Nth index
store <float>        ; Store 0th element in <float>
store <long>         ; Store 0th element in <long>
store <double>       ; Store 0th element in <double>

pop st(<n>)          ; Pop 0th element to Nth index
pop <float>          ; Pop 0th element to <float>
pop <long>           ; Pop 0th element to <long>
pop <double>         ; Pop 0th element to <double>
```

- The smart assembler system recognizes what kind of push is performed through the value, reducing errors.



## 17. Flags


### <u>AT&T</u>:
```gas
pushf            # Push EFLAG/RFLAG to stack
popf             # Retrieve EFLAG/RFLAG
lahf             # Load lower 8-bits of FLAGS to AH
sahf             # Store AH to lower 8-bits of FLAGS

cli              # Disable/clear interrupt flag
sti              # Enable/set interrupt flag

fstsw %ax        # Copy FP flag to AX
fnstsw           # Same as above but non-waiting
fstsw <label>    # Copy FP flag to memory
```

- `<label>` is a label whose memory address we refer to here.


### <u>AS</u>:
```asm
push flags             ; Push EFLAG/RFLAG to stack
pop flags              ; Retrieve EFLAG/RFLAG
ah = flags             ; Load lower 8-bits of FLAGS to AH
flags = ah             ; Store AH to lower 8-bits of FLAGS

enable(interrupts)     ; Disable/clear interrupt flag
disable(interrupts)    ; Enable/set interrupt flag

ax = fpflag(w)         ; Copy FP flag to AX
ax = fpflag(n)         ; Same as above but non-waiting
<label> = fpflag       ; Copy FP flag to memory
```



## 18. Hardware Communication


### <u>AT&T</u>:

```gas
in<prefix> $<port>, %<gpr>      # Input from port
in<prefix> %<gpr1>, %<grp2>     # Input from address in GPR1

out<prefix> %<gpr>, $<port>     # Output to port
out<prefix> %<gpr2>, $<gpr1>    # Output to address in GPR1

lgdt <gdt>                      # Load <gdt> to GDT register
lidt <idt>                      # Load <idt> to IDT register
ljmp $<code>                    # Change mode
```

- `<prefix>` is prefix added after opcodes in GAS.
- It could be `b`, `w`, `l`, `q`, etc.
- `<port>` is address of the hardware port.
- `<gpr>` is a general purpose register of **16-bits** with port's address.
- `<gpr1>` & `<gpr2>` two different general purpose register of **16-bits**.
- `<code>` is hex code for a particular mode.


### <u>AS</u>:

```asm
<gpr> = input(<port>)      ; Input from port
<gpr2> = input(<gpr1>)     ; Input from address in GPR1

<gpr> = output(<port>)     ; Output to port
<gpr2> = output(<gpr1>)    ; Output to address in GPR1

gdt = @<gdt>               ; Load <gdt> to GDT register
idt = @<ldt>               ; Load <idt> to IDT register
mode <mode>                ; Change mode
```

- `<mode>` is name or code of the mode.



## 19. Interrupt Related


### <u>AT&T</u>:

```gas
hlt
int <int>    # On real/protected-mode
syscall      # On long-mode
```

- `<int>` is the interrupt value.


### <u>AS</u>:

```asm
halt
interrupt(<int>)    ; On real/protected-mode
syscall             ; On long-mode
```

---
# SSE INSTRUCTIONS



## 1. Description


This file is dedicated to listing how the AS's x86 syntax relates to its corresponding AT&T x86 syntax. From section **2** onwards, different elements of assembly's SSE instructions are discussed.



## 2. SSE Movements


### <u>AT&T</u>:

```gas
movaps %<reg1>, %<reg2>    # Move single-precision aligned
movups %<reg1>, %<reg2>    # Move single-precision unaligned
movapd %<reg1>, %<reg2>    # Move double-precision aligned
movupd %<reg1>, %<reg2>    # Move double-precision unaligned
movdqa %<reg1>, %<reg2>    # Move double quadword aligned
movdqu %<reg1>, %<reg2>    # Move double quadword unaligned

movss <mem>, %<reg>        # Memory to single-precision XMM
movss %<reg>, <mem>        # Single-precision XMM to memory
movsd <mem>, %<reg>        # Memory to single-precision XMM
movsd %<reg>, <mem>        # Single-precision XMM to memory
```

- `<reg1>` & `<reg2>` are XMM registers.
- `<reg>` is any XMM register.
- `<mem>` is either a label or memory address.


### <u>AS</u>:

```asm
<reg2> = <reg1>(float, aligned)       ; Move single-precision aligned
<reg2> = <reg1>(float, unaligned)     ; Move single-precision unaligned
<reg2> = <reg1>(double, aligned)      ; Move double-precision aligned
<reg2> = <reg1>(double, unaligned)    ; Move double-precision unaligned
<reg2> = <reg1>(quad, aligned)        ; Move double quadword aligned
<reg2> = <reg1>(quad, unaligned)      ; Move double quadword unaligned

<reg> = <mem>(float)                  ; Memory to single-precision XMM
<mem> = <reg>(float)                  ; Single-precision XMM to memory
<reg> = <mem>(double)                 ; Memory to single-precision XMM
<mem> = <reg>(double)                 ; Single-precision XMM to memory
```



## 3. SSE Arithemtic Operations


### <u>AT&T</u>:

```gas
<op><type><len> %<reg1>, %<reg2>
```

- `<op>` is the operation made.
- It could be `add`, `sub`, `mult`, `div`, etc.
- `<type>` is the type of data.
- It could be `p` (packed), `s` (scalar), etc.
- `<len>` is the length to move.
- It could be `s` (single-precision), `d` (double-precision), etc.
- `<reg1>` & `<reg2>` are the XMM registers.


### <u>AS</u>:

```asm
<reg2> <op_set>= <reg1>(<len>, <type>)
```

- `<op_set>` is the opcode set.
- It could be `+`, `-`, `*`, `/`, etc.



## 4. SSE Comparison


### <u>AT&T</u>:

```gas
cmpps $<pred>, %<reg1>, %<reg2>    # Packed comparison
comis<len> %<reg1>, %<reg2>        # Compare (ordered)
ucomis<len> %<reg1>, %<reg2>       # Compare (unordered)
```

- `<pred>` is the predicament.
- `<reg1>` & `<reg2>` are the XMM registers.
- `<len>` is the length of data to compare.
- It could be `s` (single-precision), `d` (double-precision), etc.


### <u>AS</u>:

```asm
<reg2> ?= <reg1>(<pred>)             ; Packed comparison
<reg2> ?= <reg1>(<len>, packed)      ; Compare (ordered)
<reg2> ?= <reg1>(<len>, unpacked)    ; Compare (unordered)
```



## 5. SSE Logical Operations


### <u>AT&T</u>:

```gas
p<op> %<reg1>, %<reg2>
```

- `<op>` is the operation made.
- It could be `and`, `or`, `xor`, `andn`, etc.
- `<reg1>` & `<reg2>` are two different XMM registers.


### <u>AS</u>:

```asm
<reg2> <op_set>= <reg1>
```



## 6. SSE Special Operations


### <u>AT&T</u>:

```gas
shufp<len> $<pred>, %<reg1>, %<reg2>    # Shuffles as per <pred>
```

- `<pred>` is the byte whose binary representation affects shuffling.
- `<len>` is the length of data to shuffle among.
- It could be `s`, `d`, etc.


### <u>AS</u>:

```asm
<reg2> s= <reg1>(<len>, <pred>)    ; Shuffles as per <pred>
```



## 7. SSE Unpack Operations


### <u>AT&T</u>:

```gas
unpcklps %<reg1>, %<reg2>    # Unpack lower-order elements
unpckhps %<reg1>, %<reg2>    # Unpack higher-order elements
```

- `<reg1>` & `<reg2>` are two different XMM registers.


### <u>AS</u>:

```asm
<reg2> = <reg1>.unpack(lower)     ; Unpack lower-order elements
<reg2> = <reg1>.unpack(higher)    ; Unpack higher-order elements
```



## 8. SSE Conversions


### <u>AT&T</u>:

```gas
cvtps2pd %<reg1>, %<reg2>    # Float to double
cvtpd2ps %<reg2>, %<reg1>    # Double to float

cvtsi2s<len> <label>, %<reg>    # Scalar integer to <len>
cvts<len>2si <label>, %<reg>    # <len> to scalar integer
```

- `<reg1>` & `<reg2>` are two different XMM registers.
- `<len>` is length.
- It could be `s`, `d`, etc.
- `<label>` is name of a label.


### <u>AS</u>:

```asm
<reg2> = <reg1>.float     ; Float to double
<reg2> = <reg1>.double    ; Double to float

<reg2> = <reg1>.scalar    ; <len> to scalar integer
<reg2> = <reg1>.<type>    ; Scalar integer to <len> or <type>
```

- `<type>` is basically length, but written in different way.
- It could be `float`, `double`, etc.

---
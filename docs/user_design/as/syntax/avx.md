# AVX INSTRUCTIONS



## 1. Description


This file is dedicated to listing how the AS's x86 syntax relates to its corresponding AT&T x86 syntax. From section **2** onwards, different elements of assembly's AVX instructions are discussed.



## 2. AVX Data Movements


### <u>AT&T</u>:

```gas
vmovaps %<src>, %<dest>         # Aligned float transfer
vmovs<len> %<src>, %<dest>      # Scalar transfer
```

- `<type>` is the type of transfer.
- It could be `a` (aligned), `u` (unaligned), etc.
- `<reg1>` & `<reg2>` are two different YMM registers.
- `<len>` is the length of data.
- It could be `s` (float), `d` (double), etc.


### <u>AS</u>:

```asm
<reg2> = <reg1>(<align>)    ; Aligned/unaligned transfer
<reg2> = <reg1>.scalar()    ; Scalar transfer
```

- `<align>` is the alignment status, same as `<type>` but written differently.
- It could be `aligned`, `unaligned`, etc.


# ***\*INCOMPLETE***

---
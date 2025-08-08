# BOOTSTRAPS



## 1. Level-0 Bootstrap


### 1.1 <u>Data movement</u>:

- `mov`
- `xchg`
- `lea`
- `push`, `pop`
- `pushf`, `popf` - To save or restore flag state.
- `lahf`, `sahf` - Quick flag to AH or vice-versa transfers.


### 1.2 <u>Arithmetic logic</u>:

- `add`, `sub`
- `inc`, `dec`
- `cmp`, `test` - For branching.
- `and`, `or`, `xor`
- `shl`, `shr`, `sar`
- `mul`, `imul`, `div`, `idiv`


### 1.3 <u>Control flow</u>:

- `jmp`
- `jcc` set - `je`, `jne`, etc.
- `call`, `ret`
- `loop`


### 1.4 <u>Segment & pointer setup</u>:

- `cli`, `sti` - Disable or enable interrupts while changing state.
- `hlt`
- `lgdt`, `lidt` - For protected-mode transition.
- `jmp far` - Switching real to protected.


### 1.5 <u>Device I/O</u>:

- `in`, `out` - Hardware port access.
- `rep movsb`, `rep stosb` - Large memory moves without loops.


### 1.6 <u>Optional</u>:

- `nop` - Alignment or delay filler.
- `xlat` - Byte table lookups.
- `int` - Call BIOS in real-mode.

---
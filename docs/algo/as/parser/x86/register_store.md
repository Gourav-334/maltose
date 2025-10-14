# REGISTER STOREHOUSE



## 1. Description


This file documents the implementation details about the **register storehouse**, which stores virtual (representational) value for each register.



## 2. Hardware Unit Table


|Token|Category|Sub-Category|Type|Areas|
|:-:|:-:|:-:|:-:|:-|
|`ah`|GPR|8-bit (high)|Accumulator|Text|
|`al`|GPR|8-bit|Accumulator|Text|
|`ax`|GPR|16-bit|Accumulator|Text|
|`bh`|GPR|8-bit (high)|Base|Text|
|`bl`|GPR|8-bit|Base|Text|
|`bp`|GPR|16-bit|Base pointer|Text|
|`bpl`|GPR|8-bit|Base pointer|Text|
|`bx`|GPR|16-bit|Base|Text|
|`ch`|GPR|8-bit (high)|Counter|Text|
|`cl`|GPR|8-bit|Counter|Text|
|`cx`|GPR|16-bit|Counter|Text|
|`dh`|GPR|8-bit (high)|Data I/O|Text|
|`di`|GPR|16-bit|Destination index|Text|
|`dil`|GPR|8-bit|Destination index|Text|
|`dl`|GPR|8-bit|Data I/O|Text|
|`dx`|GPR|16-bit|Data I/O|Text|
|`eax`|GPR|32-bit|Accumulator|Text|
|`ebp`|GPR|32-bit|Base pointer|Text|
|`ebx`|GPR|32-bit|Base|Text|
|`ecx`|GPR|32-bit|Counter|Text|
|`edi`|GPR|32-bit|Destination index|Text|
|`edx`|GPR|32-bit|Data I/O|Text|
|`eflag`|Flag|32-bit|Flag|Text|
|`esi`|GPR|32-bit|Source index|Text|
|`esp`|GPR|32-bit|Stack pointer|Text|
|`fpflag`|Flag|16-bit|FP flag|Text|
|`gdt`|Special register|Limiter|Global descriptor table|Text|
|`idt`|Special register|Limiter|Interrupt descriptor table|Text|
|`r10`|GPR|64-bit|R10|Text|
|`r10b`|GPR|8-bit|R10|Text|
|`r10w`|GPR|16-bit|R10|Text|
|`r11`|GPR|64-bit|R11|Text|
|`r11b`|GPR|8-bit|R11|Text|
|`r11w`|GPR|16-bit|R11|Text|
|`r12`|GPR|64-bit|R12|Text|
|`r12b`|GPR|8-bit|R12|Text|
|`r12w`|GPR|16-bit|R12|Text|
|`r13`|GPR|64-bit|R13|Text|
|`r13b`|GPR|8-bit|R13|Text|
|`r13w`|GPR|16-bit|R13|Text|
|`r14`|GPR|64-bit|R14|Text|
|`r14b`|GPR|8-bit|R14|Text|
|`r14w`|GPR|16-bit|R14|Text|
|`r15`|GPR|64-bit|R15|Text|
|`r15b`|GPR|8-bit|R15|Text|
|`r15w`|GPR|16-bit|R15|Text|
|`r8`|GPR|64-bit|R8|Text|
|`r8b`|GPR|8-bit|R8|Text|
|`r8w`|GPR|16-bit|R8|Text|
|`r9`|GPR|64-bit|R9|Text|
|`r9b`|GPR|8-bit|R9|Text|
|`r9w`|GPR|16-bit|R9|Text|
|`rax`|GPR|64-bit|Accumulator|Text|
|`rbp`|GPR|64-bit|Base pointer|Text|
|`rbx`|GPR|64-bit|Base|Text|
|`rcx`|GPR|64-bit|Counter|Text|
|`rdi`|GPR|64-bit|Destination index|Text|
|`rdx`|GPR|64-bit|Data I/O|Text|
|`rflag`|Flag|64-bit|Flag|Text|
|`rsi`|GPR|64-bit|Source index|Text|
|`rsp`|GPR|64-bit|Stack pointer|Text|
|`si`|GPR|16-bit|Source index|Text|
|`sil`|GPR|8-bit|Source index|Text|
|`sp`|GPR|16-bit|Stack pointer|Text|

$$ \text{Total = 64} $$



## 3. Data Types For Storage


- `uint8_t`: 8-bit registers
- `uint16_t`: 16-bit registers
- `uint32_t`: 32-bit registers
- `uint64_t`: 64-bit registers

---
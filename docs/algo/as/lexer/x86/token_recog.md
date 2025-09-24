# TOKEN RECOGNIZER



## 1. Description


This file documents implementation for recognizer of tokenizer, which categorizes & sub-caterizes tokens into various types. These may also be represented in form of **regular expression** for clearer understanding.



## 2. Token List


### 2.1 <u>Unit Tokens</u>:

|Token|Category|Sub-Category|Type|Areas|Status|
|:-:|:-:|:-:|:-:|:-|:-:|
|`section`|Directive|Block|Section|Outside|Soon|
|`(`|Bracket|Round|Opening|Outside|Soon|
|`.`|Operator|Numeric|Period|Outside|Soon|
|`)`|Bracket|Round|Closing|Outside|Soon|
|`{`|Bracket|Curly|Opening|Anywhere|Soon|
|`}`|Bracket|Curly|Closing|Anywhere|Soon|
|`ascii`|Data|ASCII|Unterminated|Data, Rodata|Soon|
|`string`|Data|ASCII|Terminated|Data, Rodata|Soon|
|`byte`|Data|Integer|Byte|Data, Rodata|Soon|
|`word`|Data|Integer|Word|Data, Rodata|Soon|
|`long`|Data|Integer|Long|Data, Rodata|Soon|
|`quad`|Data|Integer|Word|Data, Rodata|Soon|
|`float`|Data|Decimal|Float|Data, Rodata|Soon|
|`double`|Data|Decimal|Double|Data, Rodata|Soon|
|`longdouble`|Data|Decimal|Longdouble|Data, Rodata|Soon|
|`=`|Operator|Arithmetic|Assignation|Data, Bss, Rodata, Text|Soon|
|`,`|Operator|Separator|Comma|Data, Rodata|Soon|
|`reserve`|Directive|Memory|Reserve|Bss|Soon|
|`[`|Bracket|Square|Opening|Bss, Text|Soon|
|`]`|Bracket|Square|Closing|Bss, Text|Soon|
|`global`|Property|Scope|Global|Data, Rodata, Rodata|Soon|
|`extern`|Property|Scope|Extern|Data, Rodata, Rodata|Soon|
|`local`|Property|Scope|Local|Data, Rodata, Rodata|Soon|
|`weak`|Property|Scope|Weak|Data, Rodata, Rodata|Soon|
|`hidden`|Property|Scope|Hidden|Data, Rodata, Rodata|Soon|
|`protected`|Property|Scope|Protected|Data, Rodata|Soon|
|`rigid`|Property|Flexibility|Rigid|Data|Soon|
|`flexible`|Property|Flexibility|Flexible|Data|Soon|
|`align`|Property|Memory|Alignment|Rodata|Soon|
|`+=`|Operator|Arithmetic|Addition|Text|Soon|
|`-=`|Operator|Arithmetic|Subtraction|Text|Soon|
|`*=`|Operator|Arithmetic|Multiplication|Text|Soon|
|`/=`|Operator|Arithmetic|Division|Text|Soon|
|`&=`|Operator|Logical|AND|Text|Soon|
|`\|=`|Operator|Logical|OR|Text|Soon|
|`~=`|Operator|Logical|NOT|Text|Soon|
|`^=`|Operator|Logical|XOR|Text|Soon|
|`<<`|Operator|Bitwise|Left shift|Text|Soon|
|`>>`|Operator|Bitwise|Right shift|Text|Soon|
|`@`|Referral|Address|Pointer|Text|Soon|
|`++`|Operator|Special|Increment|Text|Soon|
|`--`|Operator|Special|Decrement|Text|Soon|
|`~`|Operator|Special|Negation|Text|Soon|
|`?=`|Operator|Special|Comparison|Text|Soon|
|`<->`|Operator|Special|Swap|Text|Soon|
|`none`|Operator|Special|Nothing|Text|Soon|
|`\|`|Operator|Special|Absolution|Text|Soon|
|`call`|Command|Function|Call|Text|Soon|
|`return`|Command|Function|Return|Text|Soon|
|`==`|Operator|Comparison|Equal|Text|Soon|
|`!=`|Operator|Comparison|Not equal|Text|Soon|
|`!`|Operator|Comparison|Not|Text|Soon|
|`<`|Operator|Comparison|Less than|Text|Soon|
|`!<`|Operator|Comparison|Not less than|Text|Soon|
|`<=`|Operator|Comparison|Less than or equal|Text|Soon|
|`!<=`|Operator|Comparison|Not less than or equal|Text|Soon|
|`>`|Operator|Comparison|Greater than|Text|Soon|
|`!>`|Operator|Comparison|Not greater than|Text|Soon|
|`>=`|Operator|Comparison|Greater than or equal|Text|Soon|
|`!>=`|Operator|Comparison|Not greater than or equal|Text|Soon|
|`push`|Command|Stack|Push|Text|Soon|
|`pop`|Command|Stack|Pop|Text|Soon|
|`store`|Command|Stack|Retrieve|Text|Soon|
|`enable`|Command|Hardware|Enable|Text|Soon|
|`disable`|Command|Hardware|Disable|Text|Soon|
|`input`|Command|Hardware|Input|Text|Soon|
|`output`|Command|Hardware|Output|Text|Soon|
|`mode`|Command|Switch|Mode|Text|Soon|
|`halt`|Command|Hardware|Halt|Text|Soon|
|`interrupt`|Command|Hardware|Interrupt|Text|Soon|
|`syscall`|Command|Hardware|Syscall|Text|Soon|
|`st`|Referrence|Stack|Float stack|Text|Soon|

$$ \text{Total = 72} $$


### 2.2 <u>Hardware Units</u>:

|Token|Category|Sub-Category|Type|Areas|Status|
|:-:|:-:|:-:|:-:|:-|:-:|
|`ah`|GPR|8-bit (high)|Accumulator|Text|Soon|
|`al`|GPR|8-bit|Accumulator|Text|Soon|
|`ax`|GPR|16-bit|Accumulator|Text|Soon|
|`bh`|GPR|8-bit (high)|Base|Text|Soon|
|`bl`|GPR|8-bit|Base|Text|Soon|
|`bp`|GPR|16-bit|Base pointer|Text|Soon|
|`bpl`|GPR|8-bit|Base pointer|Text|Soon|
|`bx`|GPR|16-bit|Base|Text|Soon|
|`ch`|GPR|8-bit (high)|Counter|Text|Soon|
|`cl`|GPR|8-bit|Counter|Text|Soon|
|`cx`|GPR|16-bit|Counter|Text|Soon|
|`dh`|GPR|8-bit (high)|Data I/O|Text|Soon|
|`di`|GPR|16-bit|Destination index|Text|Soon|
|`dil`|GPR|8-bit|Destination index|Text|Soon|
|`dl`|GPR|8-bit|Data I/O|Text|Soon|
|`dx`|GPR|16-bit|Data I/O|Text|Soon|
|`eax`|GPR|32-bit|Accumulator|Text|Soon|
|`ebp`|GPR|32-bit|Base pointer|Text|Soon|
|`ebx`|GPR|32-bit|Base|Text|Soon|
|`ecx`|GPR|32-bit|Counter|Text|Soon|
|`edi`|GPR|32-bit|Destination index|Text|Soon|
|`edx`|GPR|32-bit|Data I/O|Text|Soon|
|`eflag`|Flag|32-bit|Flag|Text|Soon|
|`esi`|GPR|32-bit|Source index|Text|Soon|
|`esp`|GPR|32-bit|Stack pointer|Text|Soon|
|`fpflag`|Flag|16-bit|FP flag|Text|Soon|
|`gdt`|Special register|Limiter|Global descriptor table|Text|Soon|
|`idt`|Special register|Limiter|Interrupt descriptor table|Text|Soon|
|`r10`|GPR|64-bit|R10|Text|Soon|
|`r10b`|GPR|8-bit|R10|Text|Soon|
|`r10w`|GPR|16-bit|R10|Text|Soon|
|`r11`|GPR|64-bit|R11|Text|Soon|
|`r11b`|GPR|8-bit|R11|Text|Soon|
|`r11w`|GPR|16-bit|R11|Text|Soon|
|`r12`|GPR|64-bit|R12|Text|Soon|
|`r12b`|GPR|8-bit|R12|Text|Soon|
|`r12w`|GPR|16-bit|R12|Text|Soon|
|`r13`|GPR|64-bit|R13|Text|Soon|
|`r13b`|GPR|8-bit|R13|Text|Soon|
|`r13w`|GPR|16-bit|R13|Text|Soon|
|`r14`|GPR|64-bit|R14|Text|Soon|
|`r14b`|GPR|8-bit|R14|Text|Soon|
|`r14w`|GPR|16-bit|R14|Text|Soon|
|`r15`|GPR|64-bit|R15|Text|Soon|
|`r15b`|GPR|8-bit|R15|Text|Soon|
|`r15w`|GPR|16-bit|R15|Text|Soon|
|`r8`|GPR|64-bit|R8|Text|Soon|
|`r8b`|GPR|8-bit|R8|Text|Soon|
|`r8w`|GPR|16-bit|R8|Text|Soon|
|`r9`|GPR|64-bit|R9|Text|Soon|
|`r9b`|GPR|8-bit|R9|Text|Soon|
|`r9w`|GPR|16-bit|R9|Text|Soon|
|`rax`|GPR|64-bit|Accumulator|Text|Soon|
|`rbp`|GPR|64-bit|Base pointer|Text|Soon|
|`rbx`|GPR|64-bit|Base|Text|Soon|
|`rcx`|GPR|64-bit|Counter|Text|Soon|
|`rdi`|GPR|64-bit|Destination index|Text|Soon|
|`rdx`|GPR|64-bit|Data I/O|Text|Soon|
|`rflag`|Flag|64-bit|Flag|Text|Soon|
|`rsi`|GPR|64-bit|Source index|Text|Soon|
|`rsp`|GPR|64-bit|Stack pointer|Text|Soon|
|`si`|GPR|16-bit|Source index|Text|Soon|
|`sil`|GPR|8-bit|Source index|Text|Soon|
|`sp`|GPR|16-bit|Stack pointer|Text|Soon|
|`\n`|Skipper|Line|Endline|Anywhere|Soon|
|`\t`|Skipper|Tabspace|Tabspace|Anywhere|Soon|

$$ \text{Total = 64} $$


### 2.3 <u>Period Tokens</u>:

|Token|Category|Sub-Category|Type|Areas|Status|
|:-:|:-:|:-:|:-:|:-|:-:|
|`.bss`|Host|Section|Bss|Outside|Soon|
|`.data`|Host|Section|Data|Outside|Soon|
|`.n`|Both|Copy|Non-waiting|Outside|Soon|
|`.rodata`|Host|Section|Read only|Outside|Soon|
|`.text`|Host|Section|Text|Outside|Soon|
|`.stack`|Host|Section|Stack|Outside|Soon|
|`.w`|Both|Copy|Waiting|Outside|Soon|

$$ \text{Total = 7} $$


### 2.4 <u>Delimiters</u>:

|Delimeter|Type|
|:-:|:-|
|` `|Excluding|
|`(`|Including|
|`)`|Including|
|`{`|Including|
|`}`|Including|
|`=`|Including|
|`"`|Including|
|`,`|Including|
|`[`|Including|
|`]`|Including|
|`+`|Including|
|`-`|Including|
|`*`|Including|
|`/`|Including|
|`<`|Including|
|`>`|Including|
|`@`|Including|
|`~`|Including|
|`?`|Including|
|`\|`|Including|
|`!`|Including|

$$ \text{Total = 21} $$


### 2.5 <u>Skippers</u>:

|Skipper|
|:-:|
|`\n`|
|`\t`|



## 3. Unknown Token FSM


![State Diagram](./assets/token_fsm1.png)



## 4. Function Declarations


```c
bool token_recog(char *str, char *mode);
```



## 5. Algorithm


1. Simply go through all the conditional statements.
2. For a matching condition, certain details need to be pushed into the record.



## 6. Details

- All parts of FSM are assembled at central FSM assembly point.
- Central assembler runs on endless loop & switch-cases within which tell which part of FSM to jump in.
- Initially, machine starts with 0th index of string & state `0`.
- The central FSM handler uses formula `state/10` to get the case for next iteration.
- Central FSM stores the global details like state.

---
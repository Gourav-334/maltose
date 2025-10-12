# TOKEN RECOGNIZER



## 1. Description


This file documents implementation for recognizer of tokenizer, which categorizes & sub-caterizes tokens into various types. These may also be represented in form of **regular expression** for clearer understanding.



## 2. Token List


### 2.1 <u>Unit Tokens</u>:

|Token|Category|Sub-Category|Type|Areas|
|:-:|:-:|:-:|:-:|:-|
|`section`|Directive|Block|Section|Outside|
|`(`|Bracket|Round|Opening|Outside|
|`.`|Operator|Numeric|Period|Outside|
|`)`|Bracket|Round|Closing|Outside|
|`{`|Bracket|Curly|Opening|Anywhere|
|`}`|Bracket|Curly|Closing|Anywhere|
|`\n`|Terminator|Escape|Endline|Anywhere|
|`\t`|Skipper|Escape|Tabspace|Anywhere|
|`ascii`|Data|ASCII|Unterminated|Data, Rodata|
|`string`|Data|ASCII|Terminated|Data, Rodata|
|`byte`|Data|Integer|Byte|Data, Rodata|
|`word`|Data|Integer|Word|Data, Rodata|
|`long`|Data|Integer|Long|Data, Rodata|
|`quad`|Data|Integer|Quad|Data, Rodata|
|`float`|Data|Fraction|Float|Data, Rodata|
|`double`|Data|Fraction|Double|Data, Rodata|
|`longdouble`|Data|Fraction|Longdouble|Data, Rodata|
|`=`|Operator|Arithmetic|Assignation|Data, Bss, Rodata, Teon|
|`,`|Operator|Separator|Comma|Data, Rodata|
|`reserve`|Directive|Memory|Reserve|Bss|
|`[`|Bracket|Square|Opening|Bss, Text|
|`]`|Bracket|Square|Closing|Bss, Text|
|`global`|Property|Scope|Global|Data, Rodata, Rodata|
|`extern`|Property|Scope|Extern|Data, Rodata, Rodata|
|`local`|Property|Scope|Local|Data, Rodata, Rodata|
|`weak`|Property|Scope|Weak|Data, Rodata, Rodata|
|`hidden`|Property|Scope|Hidden|Data, Rodata, Rodata|
|`protected`|Property|Scope|Protected|Data, Rodata|
|`rigid`|Property|Flexibility|Rigid|Data|
|`flexible`|Property|Flexibility|Flexible|Data|
|`align`|Property|Memory|Alignment|Rodata|
|`+=`|Operator|Arithmetic|Addition|Text|
|`-=`|Operator|Arithmetic|Subtraction|Text|
|`*=`|Operator|Arithmetic|Multiplication|Text|
|`/=`|Operator|Arithmetic|Division|Text|
|`&=`|Operator|Logical|AND|Text|
|`\|=`|Operator|Logical|OR|Text|
|`~=`|Operator|Logical|NOT|Text|
|`^=`|Operator|Logical|XOR|Text|
|`<<`|Operator|Bitwise|Left shift|Text|
|`>>`|Operator|Bitwise|Right shift|Text|
|`@`|Referral|Address|Pointer|Text|
|`++`|Operator|Special|Increment|Text|
|`--`|Operator|Special|Decrement|Text|
|`~`|Operator|Special|Negation|Text|
|`?=`|Operator|Special|Comparison|Text|
|`<->`|Operator|Special|Swap|Text|
|`none`|Operator|Special|Nothing|Text|
|`\|`|Operator|Special|Absolution|Text|
|`call`|Command|Function|Call|Text|
|`return`|Command|Function|Return|Text|
|`==`|Operator|Comparison|Equal|Text|
|`!=`|Operator|Comparison|Inequal|Text|
|`!`|Operator|Comparison|Not|Text|
|`<`|Operator|Comparison|Less than|Text|
|`!<`|Operator|Comparison|Not less than|Text|
|`<=`|Operator|Comparison|Less than or equal|Text|
|`!<=`|Operator|Comparison|Not less than or equal|Text|
|`>`|Operator|Comparison|Greater than|Text|
|`!>`|Operator|Comparison|Not greater than|Text|
|`>=`|Operator|Comparison|Greater than or equal|Text|
|`!>=`|Operator|Comparison|Not greater than or equal|Text|
|`push`|Command|Stack|Push|Text|
|`pop`|Command|Stack|Pop|Text|
|`store`|Command|Stack|Retrieve|Text|
|`enable`|Command|Hardware|Enable|Text|
|`disable`|Command|Hardware|Disable|Text|
|`input`|Command|Hardware|Input|Text|
|`output`|Command|Hardware|Output|Text|
|`mode`|Command|Switch|Mode|Text|
|`halt`|Command|Hardware|Halt|Text|
|`interrupt`|Command|Hardware|Interrupt|Text|
|`syscall`|Command|Hardware|Syscall|Text|
|`st`|Referrence|Stack|x87|Text|

$$ \text{Total = 72} $$


### 2.2 <u>Hardware Units</u>:

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


### 2.3 <u>Period Tokens</u>:

|Token|Category|Sub-Category|Type|Areas|
|:-:|:-:|:-:|:-:|:-|
|`.bss`|Host|Section|Bss|Outside|
|`.data`|Host|Section|Data|Outside|
|`.n`|Both|Copy|Non-waiting|Outside|
|`.rodata`|Host|Section|Read only|Outside|
|`.text`|Host|Section|Text|Outside|
|`.stack`|Host|Section|Stack|Outside|
|`.w`|Both|Copy|Waiting|Outside|

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



## 3. Function Declarations


```c
bool token_recog(char *str);
```

- `str` - The token to be checked.
- `mode` - Mode chosen for providing feedback.



## 4. Algorithm


1. Simply go through all the conditional statements.
2. For a matching condition, certain details need to be pushed into the record.

---
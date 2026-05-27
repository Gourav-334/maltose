# TOKEN RECOGNIZER



## 1. Description


This file documents implementation for recognizer of tokenizer, which categorizes & sub-caterizes tokens into various types. These may also be represented in form of **regular expression** for clearer understanding.



## 2. Token List


### 2.1 <u>Unit Tokens</u>:

|  Token       |  Category    |  Sub-Category    |  Type            |
| ------------ | ------------ | ---------------- | ---------------- |
| `section`    | `directive`  | `block`          | `section`        |
| ` `          | `delimiter`  | `separator`      | `whitespace`     |
| `(`          | `bracket`    | `round`          | `opening`        |
| `.`          | `operator`   | `numeric`        | `period`         |
| `)`          | `bracket`    | `round`          | `closing`        |
| `{`          | `bracket`    | `curly`          | `opening`        |
| `}`          | `bracket`    | `curly`          | `closing`        |
| `\n`         | `delimiter`  | `terminator`     | `endline`        |
| `\t`         | `delimiter`  | `skipper`        | `tabspace`       |
| `'`          | `stringizer` | `inverted_comma` | `single`         |
| `"`          | `stringizer` | `inverted_comma` | `double`         |
| `ascii`      | `data`       | `ascii`          | `unterminated`   |
| `string`     | `data`       | `ascii`          | `terminated`     |
| `byte`       | `data`       | `integer`        | `byte`           |
| `word`       | `data`       | `integer`        | `word`           |
| `long`       | `data`       | `integer`        | `long`           |
| `quad`       | `data`       | `integer`        | `quad`           |
| `float`      | `data`       | `fraction`       | `float`          |
| `double`     | `data`       | `fraction`       | `double`         |
| `longdouble` | `data`       | `fraction`       | `longdouble`     |
| `=`          | `operator`   | `arithmetic`     | `assigning`      |
| `,`          | `operator`   | `separator`      | `comma`          |
| `[`          | `bracket`    | `square`         | `opening`        |
| `]`          | `bracket`    | `square`         | `closing`        |
| `global`     | `property`   | `scope`          | `global`         |
| `extern`     | `property`   | `scope`          | `extern`         |
| `local`      | `property`   | `scope`          | `local`          |
| `weak`       | `property`   | `scope`          | `weak`           |
| `hidden`     | `property`   | `scope`          | `hidden`         |
| `protected`  | `property`   | `scope`          | `protected`      |
| `rigid`      | `property`   | `flexibility`    | `rigid`          |
| `flexible`   | `property`   | `flexibility`    | `flexible`       |
| `+=`         | `operator`   | `arithmetic`     | `addition`       |
| `-=`         | `operator`   | `arithmetic`     | `subtraction`    |
| `*=`         | `operator`   | `arithmetic`     | `multiplication` |
| `/=`         | `operator`   | `arithmetic`     | `division`       |
| `&=`         | `operator`   | `logical`        | `and`            |
| `\|=`        | `operator`   | `logical`        | `or`             |
| `~=`         | `operator`   | `logical`        | `not`            |
| `^=`         | `operator`   | `logical`        | `xor`            |
| `<<`         | `operator`   | `bitwise`        | `left`           |
| `>>`         | `operator`   | `bitwise`        | `right`          |
| `@`          | `referral`   | `address`        | `pointer`        |
| `++`         | `operator`   | `special`        | `increment`      |
| `--`         | `operator`   | `special`        | `decrement`      |
| `~`          | `operator`   | `special`        | `negation`       |
| `?=`         | `operator`   | `special`        | `comparison`     |
| `<->`        | `operator`   | `special`        | `swap`           |
| `none`       | `operator`   | `special`        | `nothing`        |
| `\|`         | `operator`   | `special`        | `absolution`     |
| `call`       | `command`    | `function`       | `call`           |
| `return`     | `command`    | `function`       | `return`         |
| `==`         | `operator`   | `comparison`     | `equal`          |
| `!=`         | `operator`   | `comparison`     | `inequal`        |
| `!`          | `operator`   | `comparison`     | `not`            |
| `<`          | `operator`   | `comparison`     | `lt`             |
| `!<`         | `operator`   | `comparison`     | `nlt`            |
| `<=`         | `operator`   | `comparison`     | `le`             |
| `!<=`        | `operator`   | `comparison`     | `nle`            |
| `>`          | `operator`   | `comparison`     | `gt`             |
| `!>`         | `operator`   | `comparison`     | `ngt`            |
| `>=`         | `operator`   | `comparison`     | `gt`             |
| `!>=`        | `operator`   | `comparison`     | `nge`            |
| `push`       | `command`    | `stack`          | `push`           |
| `pop`        | `command`    | `stack`          | `pop`            |
| `store`      | `command`    | `stack`          | `retrieve`       |
| `enable`     | `command`    | `hardware`       | `enable`         |
| `disable`    | `command`    | `hardware`       | `disable`        |
| `input`      | `command`    | `hardware`       | `input`          |
| `output`     | `command`    | `hardware`       | `output`         |
| `mode`       | `command`    | `switch`         | `mode`           |
| `halt`       | `command`    | `hardware`       | `halt`           |
| `interrupt`  | `command`    | `hardware`       | `interrupt`      |
| `syscall`    | `command`    | `hardware`       | `syscall`        |
| `st`         | `referrence` | `stack`          | `x87`            |

$$ \text{Total = 75} $$


### 2.2 <u>Hardware Units</u>:

|  Token   |  Category  |  Sub-Category  |  Type         |
| -------- | ---------- | -------------- | ------------- |
| `ah`     | `gpr`      | `8h-bit`       | `accumulator` |
| `al`     | `gpr`      | `8l-bit`       | `accumulator` |
| `ax`     | `gpr`      | `16-bit`       | `accumulator` |
| `bh`     | `gpr`      | `8h-bit`       | `base`        |
| `bl`     | `gpr`      | `8l-bit`       | `base`        |
| `bp`     | `gpr`      | `16-bit`       | `base_ptr`    |
| `bpl`    | `gpr`      | `8l-bit`       | `base_ptr`    |
| `bx`     | `gpr`      | `16-bit`       | `base`        |
| `ch`     | `gpr`      | `8h-bit`       | `counter`     |
| `cl`     | `gpr`      | `8l-bit`       | `counter`     |
| `cx`     | `gpr`      | `16-bit`       | `counter`     |
| `dh`     | `gpr`      | `8h-bit`       | `data_io`     |
| `di`     | `gpr`      | `16-bit`       | `destination` |
| `dil`    | `gpr`      | `8l-bit`       | `destination` |
| `dl`     | `gpr`      | `8l-bit`       | `data_io`     |
| `dx`     | `gpr`      | `16-bit`       | `data_io`     |
| `eax`    | `gpr`      | `32-bit`       | `accumulator` |
| `ebp`    | `gpr`      | `32-bit`       | `base_ptr`    |
| `ebx`    | `gpr`      | `32-bit`       | `base`        |
| `ecx`    | `gpr`      | `32-bit`       | `counter`     |
| `edi`    | `gpr`      | `32-bit`       | `destination` |
| `edx`    | `gpr`      | `32-bit`       | `data_io`     |
| `eflag`  | `flag`     | `32-bit`       | `flag`        |
| `esi`    | `gpr`      | `32-bit`       | `source`      |
| `esp`    | `gpr`      | `32-bit`       | `stack_ptr`   |
| `fpflag` | `flag`     | `16-bit`       | `fpflag`      |
| `gdt`    | `special`  | `limiter`      | `gdt`         |
| `idt`    | `special`  | `limiter`      | `idt`         |
| `r10`    | `gpr`      | `64-bit`       | `r10`         |
| `r10b`   | `gpr`      | `8-bit`        | `r10`         |
| `r10w`   | `gpr`      | `16-bit`       | `r10`         |
| `r11`    | `gpr`      | `64-bit`       | `r11`         |
| `r11b`   | `gpr`      | `8-bit`        | `r11`         |
| `r11w`   | `gpr`      | `16-bit`       | `r11`         |
| `r12`    | `gpr`      | `64-bit`       | `r12`         |
| `r12b`   | `gpr`      | `8-bit`        | `r12`         |
| `r12w`   | `gpr`      | `16-bit`       | `r12`         |
| `r13`    | `gpr`      | `64-bit`       | `r13`         |
| `r13b`   | `gpr`      | `8-bit`        | `r13`         |
| `r13w`   | `gpr`      | `16-bit`       | `r13`         |
| `r14`    | `gpr`      | `64-bit`       | `r14`         |
| `r14b`   | `gpr`      | `8-bit`        | `r14`         |
| `r14w`   | `gpr`      | `16-bit`       | `r14`         |
| `r15`    | `gpr`      | `64-bit`       | `r15`         |
| `r15b`   | `gpr`      | `8-bit`        | `r15`         |
| `r15w`   | `gpr`      | `16-bit`       | `r15`         |
| `r8`     | `gpr`      | `64-bit`       | `r8`          |
| `r8b`    | `gpr`      | `8-bit`        | `r8`          |
| `r8w`    | `gpr`      | `16-bit`       | `r8`          |
| `r9`     | `gpr`      | `64-bit`       | `r9`          |
| `r9b`    | `gpr`      | `8-bit`        | `r9`          |
| `r9w`    | `gpr`      | `16-bit`       | `r9`          |
| `rax`    | `gpr`      | `64-bit`       | `accumulator` |
| `rbp`    | `gpr`      | `64-bit`       | `base_ptr`    |
| `rbx`    | `gpr`      | `64-bit`       | `base`        |
| `rcx`    | `gpr`      | `64-bit`       | `counter`     |
| `rdi`    | `gpr`      | `64-bit`       | `destination` |
| `rdx`    | `gpr`      | `64-bit`       | `data_io`     |
| `rflag`  | `flag`     | `64-bit`       | `flag`        |
| `rsi`    | `gpr`      | `64-bit`       | `source`      |
| `rsp`    | `gpr`      | `64-bit`       | `stack_ptr`   |
| `si`     | `gpr`      | `16-bit`       | `source`      |
| `sil`    | `gpr`      | `8l-bit`       | `source`      |
| `sp`     | `gpr`      | `16-bit`       | `stack_ptr`   |

$$ \text{Total = 64} $$


### 2.3 <u>Period Tokens</u>:

|  Token    |  Category  |  Sub-Category  |  Type         |
| --------- | ---------- | -------------- | ------------- |
| `.bss`    | `host`     | `section`      | `bss`         |
| `.data`   | `host`     | `section`      | `data`        |
| `.n`      | `both`     | `copy`         | `non-waiting` |
| `.rodata` | `host`     | `section`      | `r`           |
| `.text`   | `host`     | `section`      | `text`        |
| `.sack`   | `host`     | `section`      | `stack`       |
| `.w`      | `host`     | `copy`         | `waiting`     |

$$ \text{Total = 7} $$



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
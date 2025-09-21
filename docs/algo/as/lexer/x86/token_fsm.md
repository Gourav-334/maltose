# TOKEN FINITE STATE MACHINE



## 1. Description


This file documents implementation for FSM of tokenizer, which categorizes & sub-caterizes tokens into various types. These may also be represented in form of **regular expression** for clearer understanding.



## 2. Representation


### 2.1 <u>Token List</u>:

|Token|Category|Sub-Category|Type|Areas|
|:-:|:-:|:-:|:-:|:-|
|`section`|Directive|Block|Section|Outside|
|`(`|Bracket|Round|Opening|Outside|
|`.`|Operator|Numeric|Period|Outside|
|`)`|Bracket|Round|Closing|Outside|
|`{`|Bracket|Curly|Opening|Anywhere|
|`}`|Bracket|Curly|Closing|Anywhere|
|`ascii`|Data|ASCII|Unterminated|Data, Rodata|
|`string`|Data|ASCII|Terminated|Data, Rodata|
|`byte`|Data|Integer|Byte|Data, Rodata|
|`word`|Data|Integer|Word|Data, Rodata|
|`long`|Data|Integer|Long|Data, Rodata|
|`quad`|Data|Integer|Word|Data, Rodata|
|`float`|Data|Decimal|Float|Data, Rodata|
|`double`|Data|Decimal|Double|Data, Rodata|
|`longdouble`|Data|Decimal|Longdouble|Data, Rodata|
|`=`|Operator|Arithmetic|Assignation|Data, Bss, Rodata, Text|
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
|`!=`|Operator|Comparison|Not equal|Text|
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


### 2.2 <u>State Diagram</u>:

![State Diagram](./assets/token_fsm1.png)



## 3. Function Declarations


### 3.1 <u>Central Function</u>:

```c
bool token_fsm_main(char *str, unsigned short int start, char *mode);
```

- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.


### 3.2 <u>Part Function</u>:

```c
void token_fsmN(char *str, unsigned short int start, signed short int *state);
```

- `N` - A whole number representing a part of FSM, each part containing 10 states.
- `str` - String which is passed to the FSM.
- `start` - Index of string to start running machine.
- `state` - Initial state of the machine.



## 4. Algorithm


### 4.1 <u>Steps (Central FSM)</u>:

1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Until the string hasn't been read completely, or no mistake is found, keep reading each char.
3. Use the formula `state/10` to know which part of FSM to run.
4. For an invalid state, display error on screen.
5. Also displays message/diagnosis for unknown state.


### 4.2 <u>Steps (Part of FSM)</u>:

1. Check if the mode passed is valid or not, proceed if valid or halt otherwise.
2. Change state as per the read symbol (char).



## 5. Details

- All parts of FSM are assembled at central FSM assembly point.
- Central assembler runs on endless loop & switch-cases within which tell which part of FSM to jump in.
- Initially, machine starts with 0th index of string & state `0`.
- The central FSM handler uses formula `state/10` to get the case for next iteration.
- Central FSM stores the global details like state.

---
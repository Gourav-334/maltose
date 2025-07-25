# LEVEL-0 BOOTSTRAP INTERFACE



## 0. Description


This file describes about the interface planned to be implemented in **DEC AS-1**, where assembler will be created from existing toolchain.



## 1. List Of Features


- Intuitive assembly syntax
- Smart opcode picking mechanism
- User-friendly errors & warnings
- Multi-pass system
- Conditional recovery system
- Deep user control



## 2. Interface


### 2.1 <u>AS syntax (x86)</u>:

#### 2.1.1 INTRODUCTION:
- Everything in section **2.1** is just representation of equivalent GAS instructions.
- This section doesn't explain or teach about **x86** processor architecture.
- Full explanation can be found in manual/ guide book.
- In each sub-section, first instruction is of **GAS**, while second one is of **DEC AS**.
- Each possible comparison is written & explained in `as_syntax.md`.

#### 2.1.2 DEFINING SECTION:
```gas
.section .data        # .section .<sec_name>
```

```asm
section(data):        ; section(<sec_name>)
```

#### 2.1.3 DEFINING LABEL SCOPE
```gas
.global _start        # .<scope> <label>
```

```asm
global _start        ; <scope> <label>
```

#### 2.1.4 SUB-ROUTINE
```gas
_start:
    # Sub-routine instructions
```

```asm
_start {
    ; Sub-routine instructions
}
```

#### 2.1.5 DEFINING DATA
```gas
num: .word 12        # <name>: .<type> <value>
```

```asm
word num = 12        ; <type> <name> = <value>
```

#### 2.1.6 MOVING A VALUE:
```gas
mov $4, %rax        # mov <src>, <dest>
```

```asm
rax = 4        ; <dest> = <src>
```

#### 2.1.7 PERFORMING OPERATION:
```gas
add $2, %r11        # <op> <src>, <dest>
```

```asm
r11 += 2        ; <dest> <op_set>= <src>
```


### 2.2 <u>Command-line commands</u>:

#### 2.2.1 PRIMARY ACCESS BINARY:
- Primary binary for **AS** is accessed with `dec-as`.
- After `dec-as`, follows file names & flags.

```
dec-as <src_file> <dest_file> -<flag1> -<flag2> ... -<flagn>
```

#### 2.2.2 ASSEMBLING FLAGS:
- `deb` - Add debugging information
- `dev` - Display developer info
- `obj` - Convert to object (`.o`) file
- `opt` - Optimize code
- `war` - Disable warnings

#### 2.2.3 CFG REPRESENTATION:
- We can represent command-line `dec-as` commands using **context-free grammar**.
- The following table shows terminal symbols & what they represent.

|Symbol|Represents|Type|
|:-:|:-|:-:|
|$S$|Start symbol|Start ($S$)|
|$a$|Compulsory assembler binary|Terminal ($\Sigma$)|
|$b$|Source file|Terminal ($\Sigma$)|
|$c$|Destination file|Terminal ($\Sigma$)|
|$A$|Set of flags|Non-terminal ($N$)|

- Production rules ($P$) would be as following.

$$ S\;\rightarrow\;abcA $$
$$ A\;\rightarrow\;dA\;|\;d\;|\;\epsilon $$

#### 2.2.4 EXAMPLE:

- Assume we need to assemble a file `test.asm` into object file `test.o`.
- We want to add debugging information (`deb`) & display developer information (`dev`).
- So, the command would be as below.

```sh
dec-as test.asm test.o -deb -dev
```

- Let's check it out using CFG.
- If we derive $S$ (start symbol) from it, then its a valid command.
- $dec-as$ is the assembly binary, $src$ is source file, $dest$ is destination file, $deb$ & $dev$ are flags.

$$ <dec-as><src><dest><deb><dev> $$
$$ =\;<a><b><c><d><d> $$
$$ =\;abcdd $$
$$ =\;abcdA $$
$$ =\;abcA $$
$$ =\;S $$

- 4th and 5th lines are result of using rule $A\;\rightarrow\;d\;|\;dA$.
- Though this representation helps readers to know the right way to write the command, it is validated using **finite-state machine** (FSM) in code.

---
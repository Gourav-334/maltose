# COMMANDS TO ASSEMBLER



## 1. Description


This file describes about the interface planned to be implemented in **DEC AS-1**, where assembler will be created from existing toolchain.



## 2. Interface


### 2.1 <u>Accessing assembly binary</u>:

- Primary binary for **AS** is accessed with `dec-as`.
- After `dec-as`, follows file names & flags.

```
dec-as <src_file> <dest_file> -<flag1> -<flag2> ... -<flagn>
```


### 2.2 <u>Flags to assembler</u>:

- `deb` - Add debugging information
- `dev` - Display developer info
- `log` - Log all scanning process
- `mod=x` - Runs in `x` mode (`host` or `metal`).
- `opt` - Optimize code
- `nwr` - Disable warnings


### 2.3 <u>Proving syntax stability</u>:

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


### 2.4 <u>Example</u>:

- Assume we need to assemble a file `test.asm` into object file `test.o`.
- We want to add debugging information (`deb`) & display developer information (`dev`).
- So, the command would be as below.

```sh
dec-as test.asm test.o -deb -dev
```

- Let's check it out using CFG.
- If we derive $S$ (start symbol) from it, then its a valid command.
- $dec-as$ is the assembly binary, $src$ is source file, $dest$ is destination file, $deb$ & $dev$ are flags.

$$ <dec-as>\;<src>\;<dest>\;<deb>\;<dev> $$
$$ =\;<a>\;<b>\;<c>\;<d>\;<d> $$
$$ =\;abcdd $$
$$ =\;abcdA $$
$$ =\;abcA $$
$$ =\;S $$

- 4th and 5th lines are result of using rule $A\;\rightarrow\;d\;|\;dA$.
- Though this representation helps readers to know the right way to write the command, it is validated using **finite-state machine** (FSM) in code.

---

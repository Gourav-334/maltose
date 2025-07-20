# DEC AS-1 FEATURES



## 0. Introduction


- **DEC AS** introduces a set of unique features not commonly found in traditional assemblers.
- These features address usability concerns (especially for beginners) as well as architectural flexibility and long-term maintainability.
- All unique features are mentioned starting from point **0** onwards.



## 1. Intuitive Syntax


- Traditional assemblers (***Intel***/***AT&T***) often impose complex, unintuitive syntax.


### Intel syntax:

```asm
mov rax, 4
```

### AT&T syntax:

```gas
movq $4, %rax
```

- The syntaxes we just saw are often bind with many rules which don't come intuitive.
- This seldom diverges focus of beginners from understanding underlying processor's architecture to the syntax.
- So, one might wish to write it in a more understandable & arithmetic syntax.
- For that, we have an example below.

### DEC AS syntax:

```asm
rax += 4
```

- This syntax can be naturally understood by a beginner & expert alike.
- Here, opcodes are embed in arithmetic symbols.
- The assembler here is smart to understand the combination of opcode, destination & source to know which opcode to pick.
- Operationally, it retains the functionality same as that of a traditional assembler, while benefitting programmers simultaneously.



## 2. Parsing Phases


- Usually, assemblers have **two** parsing phases.
- These phases are - ***Label resolution*** & ***code generation***
- **<u>Label resolution</u>:** Verifying & extacting labels from the code before recording them in symbol table.
- **<u>Code generation</u>:** Generating machine code for the modified user assembly code.
- But we would be using **four** phases.
- These would be - ***Block verification***, ***semantic verification***, ***logic verification & label resolution*** & ***code generation***.
- Such a security conscious system ensures not only that user gets precise feedback, but also the high scalability & maintainability of the project on long run.



## 3. Independence


- Independence from existing tools used in a compiler/ interpreter /assembler based project is achievable through ***bootstrapping***.
- **Bootstrapping** is a process of writing programming language from an existing one, then rewriting it in the created language.
- If the syntax grammar & architecture is strong, then the bootstrapped version is believed to be stable.
- Its also done in many stages, not just one.
- And before its done, a dependency on previous toolchains is present there.

---
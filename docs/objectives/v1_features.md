# VERSION 1 - FEATURES


## **0. Introduction**

While there is nothing like **"unique features"** planned out yet, the differences could be called as unique. This uniqueness might appear only in the form of syntax we write, not the instruction itself. This is beacause the instructions remain hardcoded by the chip making vendors, which can't be altered through any means.


## **1. Intuitive Syntax**

- The syntax style of assemblers are often very complex & intimidating.

### Intel syntax:

```asm
mov rax, 4
```

### AT&T syntax:

```gas
movq $4, %rax
```

- While they come naturally to the programming, these syntax are often bind with many rules.
- And many might thus prefer using higher-level language due to lack of resources to learn from.
- For the same instruction as written in above snippets, a more intuitive & secured syntax might be cleaner and better for many.

### Maltose syntax:

```malt
rax = rax + 4
```

- While this is just a small instruction, more complex instructions can be made easier with equal or better performance.


## **2. Interoperability**

- Interoperability is the ability of components to be used with other components.
- This often comes as integration with other compilers & tools.
- Definitely because MALTOSE is system level project, the low-level compilers like ***Rustc***, ***GCC*** etc will be given priority.


## **3. Portability**

- Well, it is not planned yet, but its best to consider it at very starting with the postability.
- This might be done with ***bytecode engine*** to run on all operating system kernels runnable on **x86** processor family.


## **4. Independence**

- Independence from existing tools used in a compiler/ interpreter /assembler based project is achievable through ***bootstrapping***.
- **Bootstrapping** is a process of writing programming language from an existing one, then rewriting it in the created language.
- If the syntax grammar & architecture is strong, then the bootstrapped version is believed to be stable.
- Its also done in many stages, not just one.
- And before its done, a dependency on previous toolchains is there.

---
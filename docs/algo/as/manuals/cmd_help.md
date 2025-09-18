# COMMAND-LINE HELP



## 1. Description


This file records implementation of command-line help manual.



## 2. Command Representation


```sh
<dec-as> <dest_file> <src_file> -<flag1> -<flag2> ... -<flagN>
```

- `<dec-as>` is variable representing assembler binary, or a direct reference to it.
- `<dest_file>` is the path & name given to destination file.
- `<src_file>` is the name & path of source file.
- `<flag1>, <flag2>`, etc, are flags passed in command.
- `...` represents possible commands written between flag `<flag2>` & `<flagN>`.



## 4. Functions


### 4.1 <u>Representation</u>:

```c
void cmd_help_repr();
```

- Pseudo representation of the command.
- Telling about each pseudo argument.


### 4.2 <u>Rules</u>:

```c
void cmd_help_rules();
```

- Minimum & maximum number of arguments.
- Every flag must be passed just once.



### 4.3 <u>Flags</u>:

```c
void cmd_help_flags();
```

- Mentions about each flag.

---
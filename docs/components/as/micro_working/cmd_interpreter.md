# README (`docs/components/as/micro_working/`)



## 1. Description


This file explains working of the **command interpreter** at a micro-level, with its sub-components.



## 2. Stepwise Flow


1. Command interpreter takes in the user command in form of arguments.
2. These arguments are used as tokens themselves & parsed with FSM.
3. Warnings or errors might appear, which are trapped by ambiguity handler.
4. These ambiguities are shown with their IDs for troubleshooting.
5. If no error is faced, the flow continues further.
6. Various flags are set as per the user's request.
7. Then control is passed to the lexer.



## 3. Graphical Representation


<img src="./assets/cmd_interpreter.png" alt="Command Interpreter" style="width:500px; height:auto;" />



## 4. Involved Components


- Finite state machine
- Error log
- Warning log
- Request flag statuses

---
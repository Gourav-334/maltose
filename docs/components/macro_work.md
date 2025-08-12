# MACRO-LEVEL WORKING



## 1. Description


This file explains the flow of assembler's working along from a top view, or as a bigger (macro) picture.



## 2. Stepwise Flow

- Assembling of the source assembly code.
- Check & display for any error or ambiguity in command.
- For ambiguity free command, load the file stream into RAM.
- Start parsing & parallelly cleansing the code from RAM.
- For any error or ambiguity, display everything on the terminal.
- For successful parsing, cleanse the code further by replacing the labels with values/instructions.
- Now as per the mode, generate binaries for that code.



## 3. Graphical Representation

---
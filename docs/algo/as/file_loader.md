# FILE LOADER



## 1. Description


This file records implementation of **file loader**, which loads data from a file (disk) to RAM. Reading from RAM has lower overhead & ease than to in disk.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool load_file(char *path, char *mode);
```

- `path` - Path to the target (source) file.
- `mode` - Programmer chosen mode to display feedback.


### 2.2 <u>Steps</u>:

1. Check if the passed mode for feedback is valid, proceed if yes.
2. Check if the passed file exists or not, proceed if yes.
3. Open the file in read mode.
4. Check for correct opening of the file.
5. Go to the end of the file, store the cursor position somewhere.
6. Go to the offset of file, differentiate from current value.
7. Check for correct seeking of cursor.
8. Calculate the required number of bytes as per their difference.
9. Dynamically allocate memory for a global string variable.
10. Check the correct working of memory allocator.
11. Load all the content of file into it.
12. Check if all the contents were read.


### 2.3 <u>Time Complexity</u>:

- **Best case -** $O(1)$ due to return at first encounter itself (if found at 0th index).
- **Average case -** $O(n.m)$ for matching each character of target string with illegal character set.
- **Worst case -** $O(n.m)$ Same reason as for the **average case**.

---
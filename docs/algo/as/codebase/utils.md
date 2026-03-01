# COMMAND INTERPRETER MANUAL



## 0. Before Reading


### 0.1 <u>Reference Places</u>:

- **n.1 Location:** Inspect directories in `src/`
- **n.2 Role:** Inspect algorithm & source code
- **n.3 Identifiers:** Inspect algorithm & source code
- **n.4 Working:** Inspect algorithm
- **n.5 Side-note:** Inspect algorithm

>**<u>NOTE</u>:** Some sections could be absent/null if their explanations are not applicable.


### 0.2 <u>Order Of Writing</u>:

|Sno.|File Name|Sub-Component Name|
|:-:|:-|:-|
|1|`path_valid.c`|Filepath Validator|
|2|`pop_dealloc.c`|Popper & Deallocator|
|3|`push_alloc.c`|Pusher & Allocator|
|4|`case_ins_match.c`|Case-Insensitive Matcher|
|5|`ill_char_scan.c`|Illegal Character Scanner|


### 0.3 <u>Role Explanation</u>:

For role, explain the use of particular program and also what they return (if not of type `void`).


### 0.4 <u>Identifier Groupings</u>:

|Sno|Group|Explanation Style|
|:-:|:-|:-:|
|1|Function & parameters|One-by-one|
|2|Macros|Group-wise|
|3|Structures & unions|One-by-one|
|4|Variables|Group-wise|

>**<u>NOTE</u>:** Groups for each sub-sections (*HEADER*, *SOURCE (GLOBAL)*, *SOURCE (LOCAL)*) are separated.



## 1. Filepath Validator


### 1.1 <u>Location</u>:

```sh
src/utils/file_sys/path_valid.c
```


### 1.2 <u>Role</u>:

- `path_valid.c` checks if a given filepath actually exists or not.
- It basically checks if a new file can actually be added to given path or not.
- Its about path and not about file.


### 1.3 <u>Identifier</u>:

#### **1.3.1 HEADER**
```c
bool check_path(char *path, bool exist, char *mode);
```
- `path` - The path with filename which has to be validated.
- `exist` - Tells if the filename (if included) currently exists.
- `mode` - Mode chosen by programmer for functions to run on.

#### **1.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **1.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
FILE *file = NULL;
int rm_ret;
```
- `file` - Pointer to the filename (if any) added at the end of filepath.
- `rm_ret` - Catches return value when a file is removed.


### 1.4 <u>Working</u>:

1. Check if right mode is passed in argument.
2. Check if the passed path doesn't include file's name, thus `/`.
3. If so, append a custom file name to it & assume that this file must exist in future.
4. If filename included in passed path should already exists, run a read operation.
5. For a success or failure, write feedback as per the mode.
6. Else if the filename included must exist later, run a read operation.
7. For a success or failure, write feedback as per the mode.
8. If file wasn't read, run a write operation.
9. For a success or failure, write feedback as per the mode.
10. If was a success, delete the file back.


### 1.5 <u>Side-Node</u>:

$$ NULL $$



## 2. Popper & Deallocater


### 2.1 <u>Location</u>:

```sh
src/utils/str_ops/pop_dealloc.c
```


### 2.2 <u>Role</u>:

- `pop_dealloc.c` deallocates string's last character (before null terminator).
- Null terminator is shifted by a byte after deallocation.


### 2.3 <u>Identifier</u>:

#### **2.3.1 HEADER**
```c
void pop_dealloc(char **str, char *mode);
```
- `str` - String passed to make operations on.
- `mode` - Mode chosen by programmer for functions to run on.

#### **2.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **2.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
long int str_len;
```
- `str_len` - Contains the length of passed string.


### 2.4 <u>Working</u>:

1. Check if a valid mode was passed to the function.
2. Check if the string passed is empty or not.
3. If empty, return error.
4. Else reallocate the string with one byte less.
5. Check if the byte was deallocated or not.
6. Set the expelled byte as `0`.


### 2.5 <u>Side-Node</u>:

$$ NULL $$



## 3. Pusher & Allocater


### 3.1 <u>Location</u>:

```sh
src/utils/str_ops/push_alloc.c
```


### 3.2 <u>Role</u>:

- `push_alloc.c` safely allocates a byte at the end of the string, writes requested character there, and shifts the null terminator forward by one byte.


### 3.3 <u>Identifier</u>:

#### **3.3.1 HEADER**
```c
void push_alloc(char *str, char c, char *mode);
```
- `str` - The string on which operation has to be performed.
- `c` - The character we want to append at the end of the string.
- `mode` - Mode chosen by programmer for functions to run on.

#### **3.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **3.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
long int str_len;
```
- `str_len` - Contains the length of passed string.


### 3.4 <u>Working</u>:

1. Check which mode is being used.
2. For a valid mode, assign the correct enumeration value.
3. And for an invalid mode passed, return from the function with error.
4. Check if the character pointer (string) is pointing to `NULL`.
5. If pointing, allocate `1` byte of empty memory & set string length to `1`.
6. Provide feedback as per the mode.
7. Check for possible error during allocation of memory.
8. Then provide feedback as per the mode.
9. Reallocate `1` byte of memory to string, assign 2nd last byte the target character & last one as `NULL` terminator.
10. Then again provide feedback as per the mode.


### 3.5 <u>Side-Node</u>:
$$ NULL $$



## 4. Case-Insensitive Matcher


### 4.1 <u>Location</u>:

```sh
src/utils/str_verif/case_ins_match.c
```


### 4.2 <u>Role</u>:

- `case_ins_match.c` matches characters of two strings regardless of their casings.
- Returns the number of characters not matching if `full_match` is `true`, `1` if `false`.


### 4.3 <u>Identifier</u>:

#### **4.3.1 HEADER**
```c
int match_ins_case(char *str1, char *str2, bool full_match, char *mode);
```
- `str1` - First string passed to match with second.
- `str2` - Second string passed to match with first.
- `full_match` - User tells if it must be quick match or complete scan.
```c
#define LWR2UPR_DIFF 32
#define LOWERCASE 0
#define UPPERCASE 1
#define OTHER 2
```
- `LWR2UPR_DIFF` - Difference between an ASCII lower case & ASCII upper case character.
- `LOWERCASE` - Numerical representational code for lowercase characters.
- `UPPERCASE` - Numerical representational code for uppercase characters.
- `OTHER` - Numerical representational code for other characters.

#### **4.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **4.3.3 SOURCE (LOCAL)**
```c
int str_len;
int count = 0;
short int type;
bool mismatch = false;
```
- `str_len` - Contains the length of passed string.
- `count` - Counts the characters which don't match.
- `type` - Represents the numerical code for the current character's type (lowercase, uppercase, others).
- `mismatch` - Tells if a particular character matches or not.


### 4.4 <u>Working</u>:

1. Check if a valid mode was passed for feedback.
2. If the length of both the string mismatch, return 1.
3. Else if both have same length, start matching them.
4. Check its category (uppercase, lowercase, other).
5. If lowercase, check with lowercase.
6. If not matching, check with uppercase too.
7. If not matching, increase the count & continue.
8. Else if uppercase, check with uppercase.
9. If not matching, check with lowercase.
10. If not matching, increase the count & continue.
11. Else if its others, check as it is.
Continue if matching.


### 4.5 <u>Side-Node</u>:

$$ NULL $$



## 5. Illegal Character Scanner


### 5.1 <u>Location</u>:

```sh
src/utils/str_verif/ill_char_scan.c
```


### 5.2 <u>Role</u>:

- `ill_char_scan.c` checks for presence of illegal/unwanted character in a string.


### 5.3 <u>Identifier</u>:

#### **5.3.1 HEADER**
```c
bool scan_ill_chars(char *str, long int len, char *ill_chars, char *mode);
```
- `str` - The string that programmer is passing for scanning.
- `len` - The length of the target string, passed for memory security reasons.
- `mode` - Mode chosen by programmer for functions to run on.

#### **5.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **5.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
long int total_ill_chars = 0;
char *trash = NULL;
```
- `total_ill_chars` - Counts total number of illegal characters found.
- `trash` - Collects all the illegal characters from target string to same place.


### 5.4 <u>Working</u>:

1. Check if the mode passed doesn't exist, continue only if valid.
2. Start scanning from first character of the string.
3. Keep scanning each character linearly until the end.
4. Whenever a legal character is found, do the following.
5. For dev mode, do nothing.
6. For user mode, do nothing.
7. For debug mode, acknowledge the correctness of character.
8. Whenever an illegal character is found, do the following.
9. For dev mode, simply return true & break from function.
10. For user mode, push the illegal character into trash.
11. For debug mode, point it out on a line.
12. When scanning of all characters is complete, do the following.
13. For dev mode, return false if no illegal character was encountered.
14. For user mode, if there were illegal characters found, display them.
15. For debug mode, tell the total number of illegal characters found.


### 5.5 <u>Side-Node</u>:

$$ NULL $$

---
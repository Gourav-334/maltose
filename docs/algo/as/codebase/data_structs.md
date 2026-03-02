# DATA STRUCTURES



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
|1|`ht_inserter.c`|Hash Entry Inserter|
|2|`ht_fetcher.c`|Hash Entry Fetcher|
|3|`ht_dropper.c`|Hash Table Dropper|
|4|`inserter.c`|Linked List Node Inserter|
|5|`remover.c`|Linked List Node Remover|
|6|`displayer.c`|Linker List Displayer|
|7|`full_remover.c`|Full Linker List Remover|


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



## 1. Hash Entry Inserter


### 1.1 <u>Location</u>:

```sh
src/data_structs/hash_table/ht_inserter.c
```


### 1.2 <u>Role</u>:

- `ht_inserter.c` inserts an entry into the target hash table.
- Returns `true` if the entry is inserted successfully in the hash table.


### 1.3 <u>Identifier</u>:

#### **1.3.1 HEADER**
```c
bool insert_ht_entry(Ht_recorder *recorder, void *key, void *value, char *mode);
```
- `recorder` - Pointer to the recorder instance that contains all hash table information.
- `key` - The key for a hash table entry.
- `value` - The value for a hash table entry.

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
int index;
long int str_key_len, str_value_len;
long int sum = 0;
bool key_exists = true;
char char_key, char_value;
char *str_key=NULL, *str_value=NULL;
short short_key, short_value;
int int_key, int_value;
long long_key, long_value;
float float_key, float_value;
double double_key, double_value;
long double long_double_key, long_double_value;
Ht_entry *entry = NULL;
Ht_entry *trav = NULL;
```
- `index` - Stores the index number for new entry.
- `str_key_len` - Length of string-type key.
- `str_value_len` - Length of string-type value.
- `sum` - Sum of string-type key's character's ASCII values.
- `key_exists` - Tells if key already exists or not.
- `char_key` - Duplicate of character-type key.
- `char_value` - Duplicate of character-type value.
- `str_key` - Duplicate of string-type key.
- `str_value` - Duplicate of string-type value.
- `short_key` - Duplicate of short-type key.
- `short_value` - Duplicate of short-type value.
- `int_key` - Duplicate of int-type key.
- `int_value` - Duplicate of int-type value.
- `long_key` - Duplicate of long-type key.
- `long_value` - Duplicate of long-type value.
- `float_key` - Duplicate of float-type key.
- `float_value` - Duplicate of float-type value.
- `double_key` - Duplicate of double-type key.
- `double_value` - Duplicate of double-type value.
- `long_double_key` - Duplicate of long double type key.
- `long_double_value` - Duplicate of long double type value.
- `entry` - Pointer to the memory allocated for new entry.
- `trav` - Traversing pointer to any target hash table entry.


### 1.4 <u>Working</u>:

1. Check if a correct feedback mode was passed.
2. Check if the recorder represents the right key & value types.
3. As per the key & value types, perform casting & do the following.
4. For string apply the formula `key % buckets` for each character & sum them.
5. And for rest of the data types, apply a single `key % buckets` for the whole value.
6. Know the insertion index for the applied formula.
7. Check if the pointer at index is `NULL` or not.
8. If `NULL`, allocate the memory for the hash entry structure & fill all the data.
9. Else keep going to next connected entry until there is none left.
10. After reaching that point (last node), allocate a new hash entry & assign to this node's next pointer.
11. Then allocate the memory for the new entry & fill all the details.
12. Now if everything goes fine, return a boolean `true` value.


### 1.5 <u>Side-Node</u>:

- Imports a standalone header file `ht_struct.h` which contains structure of hash table.



## 2. Hash Entry Fetcher


### 2.1 <u>Location</u>:

```sh
src/data_structs/hash_table/ht_fetcher.c
```


### 2.2 <u>Role</u>:

- `ht_fetcher.c` fetches an entry from the hash table as per given key.
- Returns memory address of the value if found, else `NULL`.


### 2.3 <u>Identifier</u>:

#### **2.3.1 HEADER**
```c
void *fetch_ht_entry(Ht_recorder *recorder, void *key, char *mode);
```
- `recorder` - Pointer to the recorder of whole hash table.
- `key` - Key of the entry to access.
- `mode` - Chosen mode for feedback by the programmer.

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
int index;
long int str_key_len;
long int sum = 0;
bool key_exists = true;
char char_key;
char *str_key=NULL;
short short_key;
int int_key;
long long_key;
float float_key;
double double_key;
long double long_double_key;
Ht_entry *trav = NULL;
```
- `index` - Stores the index number for new entry.
- `str_key_len` - Length of string-type key.
- `sum` - Sum of string-type key's character's ASCII values.
- `key_exists` - Tells if key already exists or not.
- `char_key` - Duplicate of character-type key.
- `str_key` - Duplicate of string-type key.
- `short_key` - Duplicate of short-type key.
- `int_key` - Duplicate of int-type key.
- `long_key` - Duplicate of long-type key.
- `float_key` - Duplicate of float-type key.
- `double_key` - Duplicate of double-type key.value.
- `long_double_key` - Duplicate of long double type key.double type value.
- `trav` - Traversing pointer to any target hash table entry.


### 2.4 <u>Working</u>:

1. Check if a correct feedback mode was passed.
2. If key is of string type, sum each of its character & apply the formula `index = sum % bucket`.
3. Else for any other type of key, apply the formula directly `index = key % bucket`.
4. Access the index as per the value obtained for `index`.
5. If there is no entry at that index, return `NULL`.
6. Else if there exist entries(s), keep travelling through them until either key is found, or entries run out.
7. If an entry was found, return its address.
8. Else if none was found, return `NULL`.


### 2.5 <u>Side-Node</u>:

- Imports a standalone header file `ht_struct.h` which contains structure of hash table.



## 3. Hash Table Dropper


### 3.1 <u>Location</u>:

```sh
src/data_structs/hash_table/ht_dropper.c
```


### 3.2 <u>Role</u>:

- `ht_dropper.c` erases all entries of the target hash table, while preserving its blueprint.


### 3.3 <u>Identifier</u>:

#### **3.3.1 HEADER**
```c
void drop_ht(Ht_recorder *recorder, char *mode);
```
- `recorder` - Pointer to target hash table recorder.
- `mode` - Feedback mode chosen by the programmer.

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
Ht_entry *trav = NULL;
Ht_entry *next = NULL;
```
- `trav` - Traversing pointer to any target hash table entry.
- `next` - Pointer to the entry next to `trav`.


### 3.4 <u>Working</u>:

1. Check if a correct feedback mode was chosen.
2. Start from the first index.
3. If null, skip.
4. Else, point to the first entry.
5. Save its next address & erase it.
6. Then move to next entry.
7. Keep doing this until all the nodes from this entry is erased.
8. Then move to next index & repeat the same.
9. Keep doing this until all the indices have been cleaned.


### 3.5 <u>Side-Node</u>:

- Imports a standalone header file `ht_struct.h` which contains structure of hash table.



## 4. Linked List Node Inserter


### 4.1 <u>Location</u>:

```sh
src/data_structs/linked_list/inserter.c
```


### 4.2 <u>Role</u>:

- `inserter.c` inserts a node in front or rear of the target linked list.
- Returns `true` if whole execution was successful.


### 4.3 <u>Identifier</u>:

#### **4.3.1 HEADER**
```c
bool insert_node(Ll_recorder *recorder, char *data, bool rear, char *mode);
```
- `recorder` - The pointer to recorder/container that contains the target linked list.
- `data` - The data to plant/insert in the new node.
- `rear` - Tells if the data has to be inserted in rear or front.

#### **4.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **4.3.3 SOURCE (LOCAL)**
```c
enum Mode{DEV, USER, DEBUG} M;
```
- `Mode` - Enumerator for programmer to choose a preferred testing mode.
- `DEV` - Developer mode, tells only final result.
- `USER` - User mode, silent on failure or success.
- `DEBUG` - Logs condition of program on terminal.
```c
Ll_node *trav = NULL;
Ll_node *old_tail = NULL;
```
- `trav` - Traversing pointer to any target hash table entry.
- `old_tail` - Stores the address of older tail in case of rear insertion.


### 4.4 <u>Working</u>:

1. Check if the passed mode is valid or not.
2. Allocate memory for a node using traverser.
3. Then fill the data in the node, using same traverser.
4. Then check if any node already exists or not.
5. If not, initialize address of next node as `NULL`.
6. Place the head & tail pointer at the same node, where traverser already is.
7. Else if there already exists node(s), do the following as per insertion area.
8. If node has to be inserted in front, make address of next node point to head node.
9. Now move the head node to this newly created node.
10. Else if the node has to be inserted in rear, make the next address of tail node as this new node.
11. Then move the tail on this new node.
12. If all the operations done until now was successful, increment the node count by `1`.


### 4.5 <u>Side-Node</u>:

- Imports a standalone header file `ll_struct.h` which contains structure of linked list.



## 5. Linked List Node Remover


### 5.1 <u>Location</u>:

```sh
src/data_structs/linked_list/remover.c
```


### 5.2 <u>Role</u>:

- `remover.c` removes a node from front or rear of the target linked list.


### 5.3 <u>Identifier</u>:

#### **5.3.1 HEADER**
```c
void remove_node(Ll_recorder *recorder, bool rear, char *mode);
```
- `recorder` - Target recorder with the linked list.
- `rear` - Removes a node from rear if set to true, else from front.
- `mode` - Chosen mode to provide feedback in.

#### **5.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **5.3.3 SOURCE (LOCAL)**
```c
Ll_node *trav = NULL;
```
- `trav` - Traversing pointer to any target hash table entry.


### 5.4 <u>Working</u>:

1. Check if the passed mode is valid or not.
2. If there are no nodes at all, issue an error to user.
3. Else if there is just one node, do the following.
4. Point the head with traverser & free the only node.
5. Re-declare the head & tail node to `NULL`.
6. Else if there are multiple nodes, do the following.
7. If a front node has to be deleted, do the following.
8. Point the traverser towards head's position.
9. Point head to its next node.
10. Free the node traverse is pointing to now.
11. Else if a rear node has to be deleted, do the following.
12. Point the traverse towards head.
13. Keep traversing forward until traverser reaches a node behind last node.
14. Move the tail pointer to current node.
15. Move the traverser to the next node & free it.
16. Change the address of pointer to next node in new tail as `NULL`.
17. If the whole execution was successful, decrement the total nodes count.


### 5.5 <u>Side-Node</u>:

- Imports a standalone header file `ll_struct.h` which contains structure of linked list.



## 6. Linked List Displayer


### 6.1 <u>Location</u>:

```sh
src/data_structs/linked_list/displayer.c
```


### 6.2 <u>Role</u>:

- `displayer.c` prints information related to each node for the target linked list.


### 6.3 <u>Identifier</u>:

#### **6.3.1 HEADER**
```c
void display_nodes(Ll_recorder *recorder);
```
- `recorder` - Target recorder with the linked list.

#### **6.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **6.3.3 SOURCE (LOCAL)**
```c
Ll_node *trav = NULL;
```
- `trav` - Traversing pointer to any target hash table entry.


### 6.4 <u>Working</u>:

1. If no nodes are present, acknowledge users about that.
2. Else print the data & next address for each node using traverser, starting from head.
3. After displaying information for one node, move to next.
4. Keep doing this until a node's pointer to next address is `NULL`.


### 6.5 <u>Side-Node</u>:

- Imports a standalone header file `ll_struct.h` which contains structure of linked list.



## 7. Full Linked List Remover


### 7.1 <u>Location</u>:

```sh
src/data_structs/linked_list/full_remover.c
```


### 7.2 <u>Role</u>:

- `full_remover.c` erases whole linked list from the memory with its nodes, but preserves its blueprint.


### 7.3 <u>Identifier</u>:

#### **7.3.1 HEADER**
```c
void remove_all_nodes(Ll_recorder *recorder, char *mode);
```
- `recorder` - Target recorder with the linked list.
- `mode` - Mode for providing feedback.

#### **7.3.2 SOURCE (GLOBAL)**
$$ NULL $$

#### **7.3.3 SOURCE (LOCAL)**
$$ NULL $$


### 7.4 <u>Working</u>:

1. Simply remove each node from the head continuously (for efficiency).


### 7.5 <u>Side-Node</u>:

- Imports a standalone header file `ll_struct.h` which contains structure of linked list.

---
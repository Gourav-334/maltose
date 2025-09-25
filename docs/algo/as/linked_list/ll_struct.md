# LINKED LIST STRUCTURE



## 1. Description


This file explains implementation of linked list's structure (`struct`).



## 2. Structure


### 2.1 <u>Node</u>:

```c
typedef struct Ll_node
{
	char *data;
	struct Ll_node *next;
} Ll_node;
```

- `data` - Data that the particular node stores.
- `next` - Pointer to next linked list node.


### 2.2 <u>Recorder</u>:

```c
typedef struct Ll_recorder
{
	Ll_node *node;

	int total;

	Ll_node *head;
	Ll_node *tail;
} Ll_recorder;
```

- `total` - Total number of nodes available for a particular linked list.
- `head` - Pointer to the head (first node) of the linked list.
- `tail` - Pointer to the tail ((last node) of the linked list.

---
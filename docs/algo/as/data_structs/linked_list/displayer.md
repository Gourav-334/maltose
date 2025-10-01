# NODES DISPLAYER



## 1. Description


This file documents the implementation of nodes displayer for the linked list, which displays all the nodes in linear fashion for debugging purposes.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
void display_nodes(Ll_recorder *recorder);
```


### 2.2 <u>Steps</u>:

1. If no nodes are present, acknowledge users about that.
2. Else print the data & next address for each node using traverser, starting from head.
3. After displaying information for one node, move to next.
4. Keep doing this until a node's pointer to next address is NULL.

---
# LINKED LIST NODE INSERTER



## 1. Description


This file records implementation of **linked list node inserter**, which inserts a node in front or rear of a linked list, as per the request.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
bool insert(Ll_recorder *recorder, char *data, bool rear, char *mode);
```

- `recorder` - The pointer to recorder/container that contains the target linked list.
- `data` - The data to plant/insert in the new node.
- `rear` - Tells if the data has to be inserted in rear or front.


### 2.2 <u>Steps</u>:

1. Check if the passed mode is valid or not.
2. Allocate memory for a node using traverser.
3. Then fill the data in the node, using same traverser.
4. Then check if any node already exists or not.
5. If not, initialize address of next node as NULL.
6. Place the head & tail pointer at the same node, where traverser already is.
7. Else if there already exists node(s), do the following as per insertion area.
8. If node has to be inserted in front, make address of next node point to head node.
9. Now move the head node to this newly created node.
10. Else if the node has to be inserted in rear, make the next address of tail node as this new node.
11. Then move the tail on this new node.
12. If all the operations done until now was successful, increment the node count by `1`.

---
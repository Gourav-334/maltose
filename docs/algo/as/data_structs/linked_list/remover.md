# LINKED LIST NODE REMOVER



## 1. Description


This file documents implementation of **linked list node remover**, which removes a node from front or rear in linked list.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
void remove_node(Ll_recorder *recorder, bool rear, char *mode);
```

- `recorder` - Target recorder with the linked list.
- `rear` - Removes a node from rear if set to `true`, else from front.
- `mode` - Chosen mode to provide feedback in.


### 2.2 <u>Steps</u>:

1. Check if the passed mode is valid or not.
2. If there are no nodes at all, issue an error to user.
3. Else if there is just one node, do the following.
4. Point the head with traverser & free the only node.
5. Re-declare the head & tail node to NULL.
6. Else if there are multiple nodes, do the following.
7. If a front node has to be deleted, do the following.
8. Point the traverser towards head's position.
9. Point head to its next node.
10. Free the node traverse is pointing to now.
11. Else if a rear node has to be deleted, do the following.
12. Point the traverse towards head.
13. Keep traversing forward until traverser reaches a node behind last node.
15. Move the tail pointer to current node.
16. Move the traverser to the next node & free it.
17. Change the address of pointer to next node in new tail as NULL.
18. If the whole execution was successful, decrement the total nodes count.

---
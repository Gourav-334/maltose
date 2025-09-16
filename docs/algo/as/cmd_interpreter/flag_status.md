# FLAG STATUS STOREHOUSE



## 1. Description


This file records the implementation of flag status storehouse, discussing the attributes it would be storing.



## 2. Implementation


### 2.1 <u>Structure</u>:

```c
struct Flag {
	char *subtype;
	bool status;
};
```

- `subtype` is the subtype of the flag.
- `status` tells if it was requested or not.

---
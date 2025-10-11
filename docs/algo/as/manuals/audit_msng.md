# AUDIT MESSENGER



## 1. Description


This file describes implementation details of audit message, which with certain arguments, can print an appropriate message for a particular line.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
void msg_audit_res(
	char *code, char *filename,
	int point, int row, int column,
	char *type, char *stage,
	char *just,
	char *mode
);
```

- `filename` - Name of file being audited.
- `point` - Point in line from where the message has to be called out.
- `row` - Current row in the stage.
- `column` - Current column in the stage.
- `type` - Type of message.
- `stage` - Stage at which message is requested.
- `just` - Justification for the message.
- `mode` - Programmer chosen mode for feedback.


### 2.2 <u>Steps</u>:

1. From the point, keep moving backwards until an endline is read or `point` turns `0`.
2. After reaching, if it was an endline encountered, then move forward by `1` character.
3. Mark this position as start.
4. Then jump back to the `point`, and keep moving until `\n` or `\0` is reached.
5. Then move back by `1` character & mark it as end.
6. Calculate the distance between start & end as `count`.
7. Now move back to the start of line.
8. Then keep reading the characters into a buffer for `count` times is reached.
9. After all this, start organising message on console/terminal as per the convention being used.

---
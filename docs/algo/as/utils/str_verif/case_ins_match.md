# CASE-INSENSITIVE MATCHER



## 1. Description


This file describes the implementation details for the **case-insensitive matcher**, which matches two strings regardless of the casings of their characters.



## 2. Algorithm


### 2.1 <u>Function</u>:

```c
int match_ins_case(char *str1, char *str2, bool full_match, char *mode);
```

- `str1` - First string passed to match with second.
- `str2` - Second string passed to match with first.
- `full_match` - User tells if it must be quick match or complete scan.
- Returns the number of characters not matching if `full_match` is `true`, `1` if `false`.


### 2.2 <u>Steps</u>:

1. Check if a valid mode was passed for feedback.
2. If the length of both the string mismatch, return `1`.
3. Else if both have same length, start matching them.
4. Check its category (uppercase, lowercase, other).
5. If lowercase, check with lowercase.
6. If not matching, check with uppercase too.
7. If not matching, increase the count & continue.
8. Else if uppercase, check with uppercase.
9. If not matching, check with lowercase.
10. If not matching, increase the count & continue.
11. Else if its others, check as it is.
12. Continue if matching.

---
# LOGS



## 1. Description


This file describes how logs are to be stored for each execution, if `-log` flag was explicitly attached to execution command by user.



## 2. Interface


- Logs must be stored in separate files.
- These files must be named as per the timestamp during the time of execution.

```log
BASIC DETAILS
-------------

Time: <time>
Source file: <src>
Destination file: <dest>


FLAG DETAILS
------------

Debugging info (deb): <yes/no>
Developer info (dev): <yes/no>
Log execution (log): <yes/no>
Conversion to object (obj): <yes/no>
Code optimization (opt): <yes/no>
Disable warning (war): <yes/no>


EXECUTION LOG
-------------

<line1>:<col1>::<status>:<status_code>::<just>
<code1>
<err_point1>

<line2>:<col2>::<status>:<status_code>::<just>
<code2>
<err_point2>

...

<linen>:<coln>::<status>:<status_coden>::<just>
<coden>
<err_pointn>
```

- `<time>` stands for timestamp when execution was ordered.
- `<src>` is the name of source file during execution.
- `<dest>` is the name of destination file during execution.
- `<yes/no>` means either **yes** or **no**.
- `<linex>` is line number `x`.
- `<colx>` is character number `x` on line of enquiry.
- `<status>` is the status of execution.
- `<status_code>` is the status code.
- `<just>` is the justification for status.
- `<codex>` is the code of line number `x`.
- `<err_pointx>` is combination of spaces & cursor that point to place of conflict.

---
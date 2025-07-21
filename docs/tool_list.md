# REQUIRED TOOLS LISTING



## 1. Description


- This file mentions about the required tools & dependencies that contributors and auditors will require.
- We will list for compulsory & optional tools, along with their role or use.
- These are the same tools which were used during development, whether directly with technical focus or for improving documentation experience.
- However, there might be some tools which were decided to be used initially but no major need was seen for them.
- Some tools might include sub-tools. Information about them is written in **section 3**.



## 2. Tools


### 2.1 <u>Compulsory tools</u>:

|Tool|Requirement|Justification|Architecture/Distro|Version|
|:-:|:-|:-|:-:|:-:|
|`binutils`|Writing & inspecting assembly programs & binaries|Includes tools for writing assembly, inspecting binaries & reverse engineering.|Windows/ MacOS/ Linux (any)|>=2.42|
|Draw.io Diagrams|Making finite state machine diagrams (FSM)|FSMs are necessary for making & verifying semantic problems.|Windows/ MacOS/ Linux (any)|Any|
|`gcc`|C Programming|Primary compiler decided to be used in **DEC AS-1** (bootstrap level-0).|Windows/ MacOS/ Linux (any)|>=13.3.0|
|`git`|Version controlling|Compulsory for contributing & inspecting history.|Windows/ MacOS/ Linux (any)|>=2.43.0|


### 2.2 <u>Supplement/optional tools</u>:

|Tool|Requirement|Justification|Optional Because|Architecture/Distro|Version|
|:-:|:-|:-|:-|:-:|:-:|
|`cmake`|Compiling & linking|Used for faster compilation and linkage by replacing only differing binaries.|There is an alternative to use custom bash scripts.|Windows/ MacOS/ Linux (any)|>=3.28.3|
|`gdb`|Debugging flow issues|"GNU Debugger" is a well-known debugging tool for control flow issues.|Not required if safe programming practices & components are followed. Manual debugging is preferred.|x86_64 (Windows/ Linux \[Any\])|>=15.0.50|
|`qemu-user`|Testing binaries|Used for sandboxing and testing generated binaries.|Nothing harmful occurs in the user-level & safe mode.|x86_64 (Windows/ Linux \[Any\])|>=8.2.2|



## 3. Embedded Tools


### 3.1 `binutils`:

- `as` - GNU Assembler (GAS)
- `hexdump` - Raw binary viewer
- `ld` - Linker Editor
- `objdump` - Structure binary viewer
- `readelf` - View binary details



## 4. Tool Installation Scripts


- Scripts for installing as per respective architecture, OS & distro can be found in `../script/`.
- Scripts are named as `architecture_os_distro_type.sh`.
- For example, `x86_linux_debian_must.sh` installs must required tools for x86 Linux's Debian-based distro.

---
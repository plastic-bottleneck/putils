# PUTILS // _Simple utils for Unix systems_
> This is the main GitHub page for PUTILS.  
> It's main use is to be a part of the [Plus Linux](https://github.com/plastic-bottleneck/Plus-Linux) utils and replace busybox with something more light weight.

## //Table of content:

|util|what it does|how to use|available|
|---|---|---|---|
|ls|lists files|`ls [-l] [/path/to/file]`|🟢|
|cat|write out a file|`cat [file]`|🔴|
|rm|remove a file/directory|`rm [file/directory]`|🔴|
|cp|copy a file/directory|`cp [file/directory]`|🔴|
|ed2|edit files with ed2|`ed [file]`|🟢|
|mkdir|make directories|`mkdir [dir name]`|🔴|
|mv|move a file/directory|`mv [file/directory] [/path/to/place]`|🔴|
|pbsh|shell|-|🟢|

## //Install

> Either use the binary file or compile it from source in the `src/` folder.

### Compile using gcc:
```
gcc main.c -o [util name]
```
### Example for ls:
```
gcc main.c -o ls
```

## //Future goals:

#### 1. Add more utils like:
   - cal
   - date
   - dd
   - du
   - ...
#### 2. Make it even smaller
   - remove some code
   - maybe switch to assembly?

---

> Made by Paul alias Plastic Bottleneck  
> GitHub: https://github.com/plastic-bottleneck  
> Check out my own Distro at 1.4Mb! https://github.com/plastic-bottleneck/plus-linux

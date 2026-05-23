# Simple Shell

## Description

Simple Shell is a basic UNIX command line interpreter written in C.

This project is part of the Holberton School curriculum. The goal of this project is to recreate a simple version of the shell that can read user input, parse commands, search for executable files in the `PATH`, and run commands using system calls.

The shell works in both interactive mode and non-interactive mode.

---

## Features

- Displays a prompt in interactive mode
- Reads commands from standard input
- Splits commands into arguments
- Executes commands using `fork`, `execve`, and `wait`
- Searches for commands in the `PATH`
- Supports commands written with full paths
- Supports interactive and non-interactive mode
- Handles end of file using `Ctrl + D`
- Supports the `env` built-in
- Supports the `exit` built-in

---

## Requirements

- Ubuntu 20.04 LTS
- GCC compiler
- Betty coding style
- Allowed editors: `vi`, `vim`, `emacs`
- All files must end with a new line
- Header files must use include guards
- No memory leaks
- No more than 5 functions per file

---

## Allowed Functions and System Calls

The project may use the following functions and system calls:

```c
access
chdir
close
closedir
execve
exit
_exit
fflush
fork
free
getcwd
getline
getpid
isatty
kill
malloc
open
opendir
perror
read
readdir
signal
stat
lstat
fstat
strtok
wait
waitpid
wait3
wait4
write
```

---

## Compilation / Installation

Clone the repository:

```bash
git clone https://github.com/ghaid999/holbertonschool-simple_shell.git
```

Move into the project directory:

```bash
cd holbertonschool-simple_shell
```

Compile the project:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Run the shell:

```bash
./hsh
```

---

## Usage

After compiling the program, run it with:

```bash
./hsh
```

The shell will display a prompt and wait for the user to enter commands.

Example:

```bash
$ ./hsh
($) ls
AUTHORS  README.md  hsh  main.h  man_1_simple_shell  path.c  shell.c
($) pwd
/home/user/holbertonschool-simple_shell
($) exit
$
```

---

## Built-in Commands

| Command | Description |
| --- | --- |
| `env` | Prints the current environment variables |
| `exit` | Exits the shell |

---

## Examples

### Interactive Mode

Interactive mode means the user runs the shell and types commands manually.

```bash
$ ./hsh
($) ls
AUTHORS  README.md  hsh  main.h  man_1_simple_shell  path.c  shell.c
($) /bin/ls
AUTHORS  README.md  hsh  main.h  man_1_simple_shell  path.c  shell.c
($) pwd
/home/user/holbertonschool-simple_shell
($) env
USER=user
PATH=/usr/local/bin:/usr/bin:/bin
($) exit
$
```

### Non-Interactive Mode

Non-interactive mode means commands are passed to the shell using a pipe.

```bash
$ echo "ls" | ./hsh
AUTHORS  README.md  hsh  main.h  man_1_simple_shell  path.c  shell.c
```

Example using a full path:

```bash
$ echo "/bin/ls" | ./hsh
AUTHORS  README.md  hsh  main.h  man_1_simple_shell  path.c  shell.c
```

Example using `env`:

```bash
$ echo "env" | ./hsh
USER=user
PATH=/usr/local/bin:/usr/bin:/bin
HOME=/home/user
```

---

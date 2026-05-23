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

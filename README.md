![Unix](https://img.shields.io/badge/Unix-306998) ![ImperativeProgramming](https://img.shields.io/badge/ImperativeProgramming-306998)

# pipex 💻
Simulating the pipe and redirection shell commands in C. An introductory project for bigger UNIX projects. 

- [Evaluation](https://github.com/denisgodoy/42-pipexf#evaluation)
- [Mandatory part](https://github.com/denisgodoy/42-pipex#mandatory-part)

## Evaluation
<img width="185" alt="image" src="https://user-images.githubusercontent.com/56933400/146850520-00b112fd-4235-40a4-8b5d-505e52ece207.png"> ![badge](https://user-images.githubusercontent.com/56933400/146850411-1b08cae7-4ac0-4161-8401-29928fe87027.png)

## Mandatory part

| Program 	|  Description  |    Libraries   	|    External functions   	|
|:--------:	|:------------:	|:------------:	|:------------:	|
|  pipex 	|Produces output to outfile after the execution of two shell commands, simulating `pipe` and `redirection`.|   fcntl.h, stdlib.h, unistd.h, sys/types.h, sys/wait.h, string.h  	|  access, open, write, unlink, close, malloc, waitpid, free, pipe, dup2, execve, fork, strerror, exit|
```shell
< infile cmd1 | cmd2 > outfile #real usage
./pipex infile "cmd1" "cmd2" outfile #program usage
```

Clone and compile:
```shell
git clone https://github.com/denisgodoy/42-pipex.git pipex
cd pipex
make all
```

Create an infile with the content you want, choose two commands and execute the program:
```shell
./pipex infile "ls -la" "wc -l" outfile
```


# pipex

Pipex is a program that mimics the functionalities of the pipe operator that is used in shells of UNIX-like operating systems (like bash and zsh).

`$ cat test.txt | wc -l`

This will display the number of lines of the test.txt file to the terminal display.

Now the program won’t really be called by the pipe operator, but it will mimic its functionality as an executable program, written in the C programming language, that can be called as follows:

`$ ./pipex file1 cmd1 cmd2 file2`

which should do the same as

`$ < file1 cmd1 | cmd2 > file2`


# Pipex

The program will implement a pipe

```shell
./pipex infile.txt "ls -l" "wc -l" outfile.txt
```
## notas

https://github.com/a-ctn-a
https://github.com/emiliux136/Pipex/blob/main/esquema_emilgarc_pipex.pdf

### Test a realizar

```shell
1. Copiar el contenido de infile en outfile
./pipex infile "cat" "cat" outfile
 2. Convertir todas las letras "a" en "o"
./pipex infile "tr 'a' 'o'" "cat" outfile
3. Pasar todo el texto a mayúsculas
./pipex infile "tr 'a-z' 'A-Z'" "cat" outfile
4. Contar el número de palabras
./pipex infile "cat" "wc -w" outfile
5. Ordenar alfabéticamente el contenido del archivo
./pipex infile "sort" "cat" outfile
% ./pipex  infile"" "     " out.txt
 % ./pipex infile "ls" "" out.txt
```

## Subject

TODO 

| test    | test    |
|-------------|-------------|
| Files | Makefile, *.h, *.c |
| Func | - open, close, read, write, malloc, free, perror, strerror, access, dup, dup2, execve, exit, fork, pipe, unlink, wait, waitpid - ft_printf or any equivalent YOU coded |
| libf | yes |


Your project must comply with the following rules:
- [x] You must submit a Makefile that compiles your source files. It must not perform
unnecessary relinking.
- [ ] Your program must never terminate unexpectedly (e.g., segmentation fault, bus
error, double free, etc.).
- [ ] Your program must not have memory leaks.
- [ ] If you are unsure, handle errors the same way as the shell command:

	```shell
	< file1 cmd1 | cmd2 > file2
	```

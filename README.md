# Pipex

The program will implement a pipe

```shell
./pipex infile.txt "ls -l" "wc -l" outfile.txt
```

### Test file

Launch test.sh for some formated tests

## Requeriments

Your project must comply with the following rules:
- [x] You must submit a Makefile that compiles your source files. It must not perform
unnecessary relinking.
- [X] Your program must never terminate unexpectedly (e.g., segmentation fault, bus
error, double free, etc.).
- [X] Your program must not have memory leaks.
- [X] If you are unsure, handle errors the same way as the shell command:

	```shell
	< file1 cmd1 | cmd2 > file2
	```

## Clear for release

- [] ignore .gitignore
- [] norminette
- [] review make
- [] review test -> fail ./pipex infile"" "    " outfile
- [] review valgrind
- [] clear outputs
- [] Delete outfile
- [] Delete test.sh
- [] Delete this README.md


## Notes

https://github.com/a-ctn-a
https://github.com/emiliux136/Pipex/blob/main/esquema_emilgarc_pipex.pdf
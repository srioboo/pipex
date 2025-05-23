#!/bin/bash

clear && make re

# printf "\nCopiar el contenido de infile en outfile\n"
# ./pipex infile "cat" "cat" outfile
printf "\nConvertir todas las letras \"a\" en \"o\"\n"
./pipex infile "tr 'a' 'o'" "cat" outfile
# printf "\nPasar todo el texto a mayúsculas\n"
# ./pipex infile "tr 'a-z' 'A-Z'" "cat" outfile
#printf "\nContar el número de palabras\n"
#./pipex infile "cat" "wc -w" outfile
# printf "\nOrdenar alfabéticamente el contenido del archivo\n"
# ./pipex infile "sort" "cat" outfile

# % ./pipex  infile"" "     " out.txt
# % ./pipex infile "ls" "" out.txt

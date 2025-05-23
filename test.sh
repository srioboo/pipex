#!/bin/bash

clear && make re

# EXEC="valgrind --leak-check=summary ./pipex"
EXEC="./pipex" 
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
NAVY='\033[0;34m'
BLUE='\033[1;34m'
AQUA='\033[1;36m'
MAGENTA='\033[1;35m'
GRAY='\033[1;30m'
WHITE='\033[1;37m'
NC="\033[m"

function test1()
{
	printf "\n${GREEN}=== TEST: ${NC}Copy infile content into outfile\n"
	${EXEC} infile "cat" "cat" $1
	printf "${YELLOW}=== Result file: ${NC}$1\n\n"
	cat $1
	printf "\n${GREEN}=== END TEST${NC}\n\n"
}

function test2()
{
	printf "\n${GREEN}=== TEST: ${NC}Convert all \"a\" letter into \"o\"\n"
	${EXEC} infile "tr 'a' 'o'" "cat" $1
	printf "${YELLOW}=== Result file: ${NC}$1\n\n"
	cat $1
	printf "\n${GREEN}=== END TEST${NC}\n\n"
}

function test3()
{
	printf "\n${GREEN}=== TEST: ${NC}Convert to upper\n"
	${EXEC} infile "tr 'a-z' 'A-Z'" "cat" $1
	printf "${YELLOW}=== Result file: ${NC}$1\n\n"
	cat $1
	printf "\n${GREEN}=== END TEST${NC}\n\n"
}

function test4()
{
	printf "\n${GREEN}=== TEST: ${NC}Count words\n"
	${EXEC} infile "cat" "wc -w" $1
	printf "${YELLOW}=== Result file: ${NC}$1\n\n"
	cat $1
	printf "\n${GREEN}=== END TEST${NC}\n\n"
}

function test5()
{
	printf "\n${GREEN}=== TEST: ${NC}Order alphabetical the file content\n"
	${EXEC} infile "sort" "cat" $1
	printf "${YELLOW}=== Result file: ${NC}$1\n\n"
	cat $1
	printf "\n${GREEN}=== END TEST${NC}\n\n"
}

# % ${EXEC}  infile"" "     " out.txt
# % ${EXEC} infile "ls" "" out.txt

test1 outfile-cat.txt
test2 outfile-convert-letters.txt
test3 outfile-to-upper.txt
test4 outfile-count-words.txt
test5 outfile-order-alphabetical.txt
# test6
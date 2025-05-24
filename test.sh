#!/bin/bash

clear
make fclean
make ${1}

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

function show_result()
{
	if test $1 -eq 1
	then
		printf "${RED}KO: error in test\n"
	else
		printf "${GREEN}SUCCESS\n"
	fi
}

function test1()
{
	printf "\n${BLUE}=== TEST 0.1: ${NC}Copy infile content into outfile\n"
	${EXEC} infile "cat" "cat" ${1}
	cat < infile | cat > ${1}-orig
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	diff -u ${1} ${1}-orig
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test2()
{
	printf "\n${BLUE}=== TEST 0.2: ${NC}Convert all \"a\" letter into \"o\"\n"
	${EXEC} infile "tr 'a' 'o'" "cat" ${1}
	tr 'a' 'o' < infile | cat > ${1}-orig
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	diff -u ${1} ${1}-orig
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test3()
{
	printf "\n${BLUE}=== TEST 0.3: ${NC}Convert to upper\n"
	${EXEC} infile "tr 'a-z' 'A-Z'" "cat" ${1}
	tr 'a-z' 'A-Z' < infile | cat > ${1}-orig
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	diff -u ${1} ${1}-orig
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test4()
{
	printf "\n${BLUE}=== TEST 0.4: ${NC}Count words\n"
	${EXEC} infile "cat" "wc -w" ${1}
	cat < infile | wc -w > ${1}-orig
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	diff -u ${1} ${1}-orig
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test5()
{
	printf "\n${BLUE}=== TEST 0.5: ${NC}Order alphabetical the file content\n"
	${EXEC} infile "sort" "cat" ${1}
	sort < infile | cat > ${1}-orig
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	diff -u ${1} ${1}-orig
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test-error1()
{
	printf "\n${BLUE}=== TEST 1: ${NC}Error not enough params\n"
	${EXEC}  infile"" "     " ${1}
	status=$?
	show_result $status
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	printf "\n${BLUE}=== END TEST${NC}\n\n"
} 

function test-error2()
{
	printf "\n${BLUE}=== TEST 2: ${NC}Error empty command\n"
	${EXEC} infile "ls" "" ${1}
	status=$?
	show_result $status
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test-error3()
{
	printf "\n${BLUE}=== TEST 3: ${NC}Error no infile\n"
	${EXEC} nofile "ls" "cat" ${1}
	status=$?
	ls < nofile | cat > ${1}-orig
	printf "${YELLOW}=== Result file: ${NC}${1}\n\n"
	diff -u ${1} ${1}-orig
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test-error4()
{
	printf "\n${BLUE}=== TEST 4: ${NC}Error command a do not exists\n"
	${EXEC} infile "lisa" "cat" ${1}
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

function test-error5()
{
	printf "\n${BLUE}=== TEST 5: ${NC}Error command b do not exists\n"
	${EXEC} infile "ls" "cato" ${1}
	status=$?
	show_result $status
	printf "\n${BLUE}=== END TEST${NC}\n\n"
}

test1 outfile-cat
test2 outfile-convert-letters
test3 outfile-to-upper
test4 outfile-count-words
test5 outfile-order-alphabetical
test-error1 outfile-error1
test-error2 outfile-error2
test-error3 outfile-error3
test-error4	outfile
test-error5	outfile
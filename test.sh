#!/bin/bash

clear
make fclean
make ${1}
clear

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

function test_base()
{
	local test_num=$1
	local test_desc=$2
	local cmd1=$3
	local cmd2=$4
	local outfile=$5
	
	printf "\n${BLUE}=== TEST ${test_num}: ${NC}${test_desc}\n"
	${EXEC} infile "${cmd1}" "${cmd2}" ${outfile}
	${cmd1} < infile | ${cmd2} > ${outfile}-orig
	printf "${YELLOW}=== Result file: ${NC}${outfile}\n\n"
	diff -u ${outfile} ${outfile}-orig
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

test_base "0.1" "Copy infile content into outfile" "cat" "cat" outfile-cat
test_base "0.2" "Convert all \"a\" letter into \"o\"" "tr 'a' 'o'" "cat" outfile-to-upper
test_base "0.3" "Convert to upper" "tr 'a-z' 'A-Z'" "cat" outfile-to-upper
test_base "0.4" "Count words" "cat" "wc -w" outfile-count-words
test_base "0.5" "Order alphabetical the file content" "sort" "cat" outfile-order-alphabetical


test-error1 outfile-error1
test-error2 outfile-error2
test-error3 outfile-error3
test-error4	outfile
test-error5	outfile
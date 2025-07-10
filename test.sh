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
	local test_desc=$6
	local cmd1=$3
	local cmd2=$4
	local outfile=$5
	local infile=$2

	printf "\n${BLUE}=== TEST ${test_num}: ${NC}${test_desc}\n"
	${EXEC} ${infile} "${cmd1}" "${cmd2}" ${outfile}
	${cmd1} < ${infile} | ${cmd2} > ${outfile}-orig
	printf "${YELLOW}=== Result file: ${NC}${outfile}\n"
	# diff -u ${outfile} ${outfile}-orig
	status=$?
	show_result $status
	${EXEC} ${infile} "${cmd1}" "${cmd2}" ${outfile}; echo $?
	${cmd1} < ${infile} | ${cmd2} > ${outfile}-orig; echo $?
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

test_base "0.1" infile "cat" "cat" outfile-cat "Copy infile content into outfile"
test_base "0.2" infile "tr 'a' 'o'" "cat" outfile-to-upper "Convert all \"a\" letter into \"o\""
test_base "0.3" infile "tr 'a-z' 'A-Z'" "cat" outfile-to-upper "Convert to upper"
test_base "0.4" infile "cat" "wc -w" outfile-count-words "Count words"
test_base "0.5" infile "sort" "cat" outfile-order-alphabetical "Order alphabetical the file content"

# test-error1 outfile-error1
# test-error2 outfile-error2
# test-error3 outfile-error3
# test-error4	outfile
# test-error5	outfile

test_base "0" infile "date +%H:%M:%S" "cat" outfile infile "Muestra fecha"
test_base "1" infile "ls -l" "wc -l" outfile "Lista los archivos de infile, redirige la salida a wc -l y guarda el resultado en outfile."
test_base "2" infile "cat" "grep de" outfile  "Usa cat para mostrar el contenido de infile, filtra las líneas que contienen \"text\" con grep, y guarda el resultado en outfile"
test_base "3" infile "head -n 3" "rev" outfile "Toma las primeras 3 líneas de infile y las invierte con rev."
# Comandos de errores
test_base "4" nofile "ls -l" "wc -l" outfile "Error: El archivo de entrada nofile no existe."
test_base "5" infile "invalidcmd" "wc -l" outfile "Error: El comando invalidcmd no es válido."
test_base "6" infile "ls -l" "invalidcmd" outfile "Error: El segundo comando es inválido."
test_base "7" infile "" "wc -l" outfile "Error: El primer comando está vacío."
# Comandos especiales
test_base "8" infile "echo hola" "tr a-z A-Z" outfile "Convierte la palabra \"hola\" en mayúsculas y guarda el resultado en outfile"
test_base "9" /dev/null "echo test" "cat" outfile "Prueba con un archivo de entrada vacío (/dev/null). El resultado debería ser un archivo vacío o solo contener la salida de los comandos."
test_base "10" infile "sort" "uniq" outfile "Ordena el contenido de infile y elimina las líneas duplicadas."
# Comandos sin permisos
test_base "11" infile "echo test" "cat" no_write_file "no_write_file: Permission denied"
test_base "12" no_read_file "cat" "wc -l" outfile "NO ME FUNCIONA PORQUE NO QUITA PERMISOS CORRECTAMENTE!!"
test_base "12" /etc/shadow "cat" "wc -l" outfile "(Para permisos de lectura)"
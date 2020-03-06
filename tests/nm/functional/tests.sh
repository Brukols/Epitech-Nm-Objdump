#!/bin/bash

bold=$(tput bold)
normal=$(tput sgr0)
RED='\033[0;31m'
CYAN='\033[0;36m'
GREEN='\033[0;32m'
NC='\033[0m'


test_passed=0
test_crashed=0
test_failed=0
nb_test=0

# $1 = path binary
# $2 = description of the test
exec_test()
{
    ((nb_test++))
    echo -ne "${CYAN}${bold}Test n°$nb_test${NC} ${bold}($2)${NC} : "

    # Get the expect value
    expect=`nm $1`

    # Get the actual value
    result=`./my_nm $1`

    if [[ "$expect" == "$result" ]]
    then
        echo -ne "${GREEN}${bold}OK${NC}\n"
        ((test_passed++))
    else
        echo -ne "${RED}${bold}KO${NC}\n"
        ((test_failed++))
    fi
}

exec_ex_test32()
{
    ((nb_test++))
    echo -ne "${CYAN}${bold}Test n°$nb_test${NC} ${bold}($2)${NC} : "

    gcc "$1" -m32 > /dev/null 2>&1

    # Get the expect value
    expect=`nm`
    expect_return="$?"

    # Get the actual value
    result=`./my_nm`
    result_return="$?"

    if [[ "$expect" == "$result" ]]
    then
        if [[ "$expect_return" == "$result_return" ]]
        then
            echo -ne "${GREEN}${bold}OK${NC}\n"
            ((test_passed++))
        else
            echo -ne "${RED}${bold}KO${NC}\n"
            ((test_failed++))
        fi
    else
        echo -ne "${RED}${bold}KO${NC}\n"
        ((test_failed++))
    fi
    rm a.out
}

exec_error_test()
{
    ((nb_test++))
    echo -ne "${CYAN}${bold}Test n°$nb_test${NC} ${bold}($2)${NC} : "

    gcc "$1" -m32 > /dev/null 2>&1

    # Get the expect value
    expect=$(nm $1 2>&1 >/dev/null)
    expect_return="$?"

    # Get the actual value
    result=$(./my_nm $1 2>&1 >/dev/null)
    result_return="$?"

    if [[ "$expect" == "$result" ]]
    then
        if [[ "$result_return" == "84" ]]
        then
            echo -ne "${GREEN}${bold}OK${NC}\n"
            ((test_passed++))
        else
            echo -ne "${RED}${bold}KO${NC}\n"
            ((test_failed++))
        fi
    else
        echo -ne "${RED}${bold}KO${NC}\n"
        ((test_failed++))
    fi
}

exec_test "my_objdump" "test simple objdump"
exec_test "my_nm" "test simple nm"
exec_test "my_nm my_objdump" "hard nm"
exec_test "/usr/lib64/ld-linux-x86-64.so.2" "/usr/lib64/ld-linux-x86-64.so.2"
exec_test "src/init_elfs_struct.o" "src/init_elfs_struct.o relocatable file"
exec_test "src/init_flags.o" "src/init_flags.o relocatable file 2"
exec_test "src/init_elf_struct.o" "src/init_elf_struct.o relocatable file 3"
exec_test "src/init_sym_struct.o" "src/init_sym_struct.o relocatable file 4"
exec_test "src/init_shdr_struct.o" "src/init_shdr_struct.o relocatable file 5"
exec_test "src/init_phdr_struct.o" "src/init_phdr_struct.o relocatable file 5"
exec_ex_test32 "tests/nm/functional/test01.c" "Test file 32"
exec_error_test "tests" "Error directory"
exec_error_test "tests/nm/functional/empty" "empty file"
exec_error_test "tests/nm/functional/no_elf" "Error no elf"

exit 0
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
    expect=`objdump -fs $1`
    expect_return="$?"

    # Get the actual value
    result=`./my_objdump $1`
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
}

exec_o_test32()
{
    ((nb_test++))
    echo -ne "${CYAN}${bold}Test n°$nb_test${NC} ${bold}($3)${NC} : "

    gcc -c "$1" -o "$2" -m32 > /dev/null 2>&1

    # Get the expect value
    expect=`objdump -fs $2`
    expect_return="$?"

    # Get the actual value
    result=`./my_objdump $2`
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
    rm "$2"
}

exec_ex_test32()
{
    ((nb_test++))
    echo -ne "${CYAN}${bold}Test n°$nb_test${NC} ${bold}($2)${NC} : "

    gcc "$1" -m32 > /dev/null 2>&1

    # Get the expect value
    expect=`objdump -fs`
    expect_return="$?"

    # Get the actual value
    result=`./my_objdump`
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
    expect=$(objdump -fs $1 2>&1 >/dev/null)
    expect_return="$?"

    # Get the actual value
    result=$(./my_objdump $1 2>&1 >/dev/null)
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

exec_test "/bin/ls" "/bin/ls"
exec_test "/bin/cat" "/bin/cat"
exec_test "/bin/touch" "/bin/touch"
exec_test "/usr/lib64/ld-linux-x86-64.so.2" "/usr/lib64/ld-linux-x86-64.so.2"
exec_test "my_objdump" "my_objdump"
exec_test "my_nm" "my_nm"
exec_test "my_nm my_objdump" "hard objdump"
exec_o_test32 "tests/objdump/functional/test01.c" "tests/objdump/functional/test01.o" "Test file 32"
exec_ex_test32 "tests/objdump/functional/test01.c" "Test file 32"
exec_ex_test32 "tests/objdump/functional/test02.c" "Test file 32"
exec_error_test "tests" "Error directory"
exec_error_test "tests/nm/functional/empty" "empty file"
exec_error_test "tests/nm/functional/no_elf" "Error no elf"
exec_error_test "tests/nm/functional/truncated64" "Error truncated"
exec_error_test "tests/nm/functional/truncated64" "Error truncated 64"
exec_error_test "tests/nm/functional/truncated32" "Error truncated 32"

exit 0
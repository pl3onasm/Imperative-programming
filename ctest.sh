#!/bin/bash
# Author: David De Potter
# This script will try to compile your program and test its correctness
# by running it on all the test cases for the current problem.
# It will also perform a test for memory leaks.
# The argument is the name of the program to test.
# Example: $ ../../../ctest.sh myprogram.c 

RED="\e[31m"
GREEN="\e[32m"
BLUE="\e[34m"
CYANBACK="\e[46m"
MAGENTA="\e[35m"
BOLDBLUE="\e[1;34m"
ENDCOLOR="\e[0m"
PASSED=0

if [ $# -eq 0 ]; then
  echo -e "\nNo argument supplied!"
  echo "Usage: $0 myprogram.c"
  exit 1
fi

if ! [ -x "$(command -v gcc)" ]; then
  echo -e "\nCompiler not found! Please install gcc."
  exit 1
fi

gcc -O2 -std=c99 -pedantic -Wall -o a.out "$1" -lm

if [[ $? -ne 0 ]]; then
  echo -e "\nCompilation failed."
  exit 1
fi

echo -e "\nProgram successfully compiled as a.out\n"

DIR=./tests
if [ ! -d "$DIR" ]; then
  echo "Test folder not found!"
  echo "Please make sure you are working from the correct directory."
  exit 1
fi

readarray -d '' INFILES < <(printf '%s\0' ./tests/*.in | sort -zV)
LEN=${#INFILES[@]}
if [ $LEN -eq 0 ]; then
  echo "No test cases found!"
  exit 1
fi

if [ -t 1 ]; then echo -e "${CYANBACK}  ==:: TEST RESULTS ::==  ${ENDCOLOR}"
else echo "==:: TEST RESULTS ::=="; fi
echo

for INFILE in "${INFILES[@]}"; do
  if [ -t 1 ]; then echo -e "${BOLDBLUE}Test ${INFILE:8} ${ENDCOLOR}"
  echo -e "${BOLDBLUE}---------- ${ENDCOLOR}"
  else echo -e "Test $INFILE\n---------- "; fi
  OUTFILE="${INFILE%.*}.out"
  if [ ! -f "$OUTFILE" ]; then
    echo -e "Test file $OUTFILE not found!\n"
    continue
  else
    DIF="$(diff "$OUTFILE" <(./a.out < "$INFILE"))"
    if [ -n "$DIF" ]; then
      if [ -t 1 ]; then echo -e "${RED}Test failed.${ENDCOLOR}
      \nDifference : ${RED}$DIF${ENDCOLOR}\n"
      else echo -e "FAILED.\nDifference : $DIF\n"; fi
    else
      if [ -t 1 ]; then echo -e "${GREEN}PASSED!${ENDCOLOR}\n"
      else echo -e "PASSED!\n"; fi
      PASSED=$((PASSED + 1))
    fi
  fi
done

# Valgrind test
if [ -t 1 ]; then echo -e "${BOLDBLUE}Valgrind test ${ENDCOLOR}"
  echo -e "${BOLDBLUE}------------- ${ENDCOLOR}"
else echo -e "Valgrind test\n------------- "; fi

if ! [ -x "$(command -v valgrind)" ]; then
  echo -e "Test failed. Valgrind not installed.\n"
else
  TEST=$(valgrind ./a.out < "${INFILES["$((LEN-1))"]}" 2>&1 >/dev/null)\
  CHECK1=$(echo "$TEST" | grep -c "in use at exit: 0 bytes in 0 blocks")
  CHECK2=$(echo "$TEST" | grep -c "0 errors from 0 contexts")
  if [[ $CHECK1 -ne 0 && $CHECK2 -ne 0 ]]; then
    if [ -t 1 ]; then echo -e "${GREEN}PASSED!\n${ENDCOLOR}"
    else echo -e "PASSED!\n"; fi
    PASSED=$((PASSED + 1))
  else
    if [ -t 1 ]; then echo -e "${RED}Memory issues detected!\n${ENDCOLOR}"
    else echo -e "Memory issues detected!\n"; fi
  fi
fi

LEN=$((LEN + 1))  # Add 1 for valgrind test

if [ $PASSED -eq $LEN ]; then
  if [ -t 1 ]; then echo -e "${GREEN}You have passed all tests! \(ᵔᵕᵔ)/${ENDCOLOR}"
  else echo "All tests passed!"; fi
elif [ $PASSED -eq $(($LEN-1)) ]; then 
  if [ -t 1 ]; then echo -e "${MAGENTA}You have passed $PASSED out of $LEN tests."
  echo -e "Almost there...! (◎_◎)${ENDCOLOR}"
  else echo -e "Passed $PASSED out of $LEN tests."; fi
else    
  if [ -t 1 ]; then echo -e "${MAGENTA}You have passed $PASSED out of $LEN tests. 
  (._.)${ENDCOLOR}"
  else echo "Passed $PASSED out of $LEN tests."; fi
fi
echo

# Clean exit with status 0
exit 0


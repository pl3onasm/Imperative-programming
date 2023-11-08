#!/bin/bash
# Author: David De Potter
# Developed and tested on Ubuntu 22.04 LTS, with GNU bash, version 5.1.16

# This script will try to compile your program and test its correctness
# by running it on all the test cases for the current problem.
# It will also perform a test for memory leaks.
# The argument is the name of the program to test.
# Example: $ ../../../ctest.sh myprogram.c 

# Define some colors for output
RED="\e[31m"
GREEN="\e[32m"
BCYAN="\e[96m"
MAGENTA="\e[35m"
BBLUE="\e[1;34m"
ENDCOLOR="\e[0m"

function bcyan {
  printf "${BCYAN}$@${ENDCOLOR}"
}
function bblue {
  printf "${BBLUE}$@${ENDCOLOR}"
}
function red {
  printf "${RED}$@${ENDCOLOR}"
}
function green {
  printf "${GREEN}$@${ENDCOLOR}"
}
function magenta {
  printf "${MAGENTA}$@${ENDCOLOR}"
}

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

if [ -t 1 ]; then
  echo -e $(bcyan "┌──────────────────────────┐") 
  echo -e "$(bcyan "│")       $(bblue "TEST RESULTS")       $(bcyan "│")"
  echo -e $(bcyan "└──────────────────────────┘")
else
  echo -e "┌──────────────────────────┐" 
  echo -e "│       TEST RESULTS       │"
  echo -e "└──────────────────────────┘" 
fi
echo

# Compare the output of the program with the expected output
for INFILE in "${INFILES[@]}"; do
  if [ -t 1 ]; then 
    echo -e $(bblue "Test ${INFILE:8}")
    echo -e $(bblue "----------")
  else echo -e "Test ${INFILE:8}\n---------- "; fi
  OUTFILE="${INFILE%.*}.out"
  if [ ! -f "$OUTFILE" ]; then
    echo -e "Test file $OUTFILE not found!\n"
    continue
  else
    # run the program with the input file
    OUTPUT=$(./a.out < "$INFILE")  
    # compare the output with the expected output
    DIF="$(diff -Z "$OUTFILE" <(echo "$OUTPUT"))" 
    if [ -n "$DIF" ]; then
      # test failed
      if [ -t 1 ]; then echo -e $(red "Test failed.")
      else echo -e "Test failed."; fi
      
      EXP=0; GOT=0  # number of expected and got lines

      # print the first 6 mismatches
      echo "$DIF" | (while [[ $EXP -lt 6 ]] && read -r line; do
        if [[ $line == "<"* ]]; then
          if [ -t 1 ]; then echo -e "  $(green "$line")"
          else echo -e "  $line"; fi
          EXP=$((EXP + 1))
        elif [[ $line == ">"* ]]; then  
          if [ -t 1 ]; then echo -e "  $(red "$line")"
          else echo -e "  $line"; fi
          GOT=$((GOT + 1))
        elif [[ $line == *"c"* ]]; then 
          OUT=$(echo "$line" | cut -d "c" -f 1)
          OUT=$(echo "$OUT" | sed 's/,/-/g')
          echo -e "\n  line "$OUT""
        fi
      done
      while [[ $GOT -ne $EXP ]]; do
        # get next > lines until they match the number of < lines
        read -r line
        if [[ $line == ">"* ]]; then  
          if [ -t 1 ]; then echo -e "  $(red "$line")"
          else echo -e "  $line"; fi
          GOT=$((GOT + 1))
        fi
      done
      # indicate if there are more mismatches than shown
      LINES=$(echo "$DIF" | grep -c "<")
      if [[ $LINES -gt EXP ]]; then
        echo -e "\n  ... ($((LINES - EXP)) more)"
      fi
      echo)
    else
      # test passed
      if [ -t 1 ]; then 
        echo -e $(green "PASSED!")
        echo
      else echo -e "PASSED!\n"; fi
      PASSED=$((PASSED + 1))
    fi
  fi
done

# Check for memory issues with valgrind
if [ -t 1 ]; then 
  echo -e $(bblue "Valgrind test")
  echo -e $(bblue "------------- ")
else echo -e "Valgrind test\n------------- "; fi

if ! [ -x "$(command -v valgrind)" ]; then
  echo -e "Test failed. Valgrind not installed.\n"
else
  TEST=$(valgrind ./a.out < "${INFILES["$((LEN-1))"]}" 2>&1 >/dev/null)\
  CHECK1=$(echo "$TEST" | grep -c "in use at exit: 0 bytes in 0 blocks")
  CHECK2=$(echo "$TEST" | grep -c "0 errors from 0 contexts")
  if [[ $CHECK1 -ne 0 && $CHECK2 -ne 0 ]]; then
    if [ -t 1 ]; then echo -e $(green "PASSED!")
    else echo -e "PASSED!"; fi
    PASSED=$((PASSED + 1))
  else
    if [ -t 1 ]; then echo -e $(red "Test failed.")
      if [ $CHECK1 -eq 0 ]; then echo -e $(red "Not all memory freed."); fi
      if [ $CHECK2 -eq 0 ]; then echo -e $(red "Memory errors detected."); fi
    else echo -e "Test failed."
      if [ $CHECK1 -eq 0 ]; then echo -e "Not all memory freed."; fi
      if [ $CHECK2 -eq 0 ]; then echo -e "Memory errors detected."; fi
    fi
  fi
  echo
fi

LEN=$((LEN + 1))  # Add 1 for valgrind test

# Print final result
if [ $PASSED -eq $LEN ]; then
  if [ -t 1 ]; then echo -e $(green "You have passed all tests! \(ᵔᵕᵔ)/")
  else echo "All tests passed!"; fi
elif [ $PASSED -eq $(($LEN-1)) ]; then 
  if [ -t 1 ]; then echo -e $(magenta "You have passed $PASSED out of $LEN tests.")
  echo -e $(magenta "Almost there...! (◎_◎)")
  else echo -e "Passed $PASSED out of $LEN tests."; fi
else    
  if [ -t 1 ]; then echo -e $(magenta "You have passed $PASSED out of $LEN tests. 
  (._.)")
  else echo "Passed $PASSED out of $LEN tests."; fi
fi
echo

# Clean exit with status 0
exit 0


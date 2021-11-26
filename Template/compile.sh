#!/bin/bash

if [[ ! -f main.cpp ]];then
    echo "main.cpp not found, exiting compilation"
    exit
fi

if [[ -f main ]];then
    echo "File already compiled, removing old compilation"
    rm main
fi

echo "Compiling..."
tput setaf 6
if echo $(time g++ -g -o main main.cpp -Wall -Wextra -Wshadow -fsanitize=undefined -D_GLIBCXX_DEBUG -fsanitize=address -Wconversion -Wfloat-equal -Wduplicated-cond -Wlogical-op -fsanitize-recover ); then
	tput setaf 2
	echo "Compilation Success"
	tput setaf 7
else
	tput setaf 1
	echo "Compilation Failure"
	tput setaf 7
	exit;
fi

until [ -f main ]
do
    sleep 0.1
done

read -n 1 -r -s -p $'Press enter to continue...\n'

if [[ -f test.out ]] && [[ -f test.exp ]] && [[ -f test.in ]];then
    echo "Files present, checking outputs"
    tput setaf 6
    echo $(time ./main)
    tput setaf 7
    colordiff -b -c test.out test.exp
    if [[ $? -eq 0 ]];then
	tput setaf 2
	echo "Success"
    else
	tput setaf 1
	echo "Failure"
	tput setaf 7
	read -p "Check debug? ( y/n ) " yn
	if [[ "$yn" != "n" ]];then
		cat test.err | less -R
	fi
    fi
else
	tput setaf 1
	echo "Files not present, only compiling"
fi

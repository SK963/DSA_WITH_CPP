#!/bin/bash

truncate -s 0 output.txt
g++ main.cpp

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running program..."
    # Run the program, redirecting input from 'input.txt' and output to 'output.txt'
    ./a.out < input.txt > output.txt
    # Check if the program executed successfully
    if [ $? -eq 0 ]; then
        echo "Program executed successfully."
    else
        echo "Program execution failed."
    fi
else
    echo "Compilation failed."
fi

find . -type f -name "*.out" -exec rm {} \;

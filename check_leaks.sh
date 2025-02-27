#!/bin/bash

# Check if a line number was provided
line_number=$1

# Run valgrind with suppressions
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind_full.log \
         --verbose \
         ./src/main_test

if [ -n "$line_number" ]; then
    # First, get all matches with their context
    grep -B 10 "main_test.c:" valgrind_full.log > temp.log
    # Then filter out the specified line and its context
    awk -v line="main_test.c:$line_number" '
    {
        if (index($0, line)) {
            for(i=0; i<=10; i++) { getline }
            next
        }
        print
    }' temp.log > leaks.log
    rm temp.log
else
    # If no line number provided, show all matches
    grep -B 10 "main_test.c:" valgrind_full.log > leaks.log
fi
# ...existing code...

# Clean up the full log if you don't need it
# rm valgrind_full.log

echo "Leak check complete. Results saved in leaks.log"

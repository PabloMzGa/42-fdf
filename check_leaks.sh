#!/bin/bash

# Run valgrind with suppressions
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=valgrind_full.log \
         --verbose \
         ./src/main \
         maps/test_maps/43.fdf

# Extract all valgrind entries with context
grep -B 10 "main.c:" valgrind_full.log > temp.log

# If arguments were provided, use them as filters
if [ $# -gt 0 ]; then
    cp temp.log filtered.log

    # Process each argument as a filter
    for filter in "$@"; do
        # Create a new filtered file excluding entries containing the filter
        awk -v pattern="$filter" '
        BEGIN { in_block = 0; buffer = ""; lines = 0; }
        {
            buffer = buffer $0 "\n";
            lines++;

            if (index($0, pattern) > 0) {
                # Found pattern to exclude, reset buffer
                buffer = "";
                lines = 0;
                next;
            }

            if (lines > 10) {
                # Print the first line of the buffer and shift
                print substr(buffer, 1, index(buffer, "\n") - 1);
                buffer = substr(buffer, index(buffer, "\n") + 1);
                lines--;
            }
        }
        END {
            # Print any remaining complete blocks
            print buffer;
        }' filtered.log > tmp.log

        mv tmp.log filtered.log
    done

    mv filtered.log leaks.log
else
    # If no arguments provided, show all matches
    cp temp.log leaks.log
fi

rm temp.log

# Clean up the full log if you don't need it
# rm valgrind_full.log

echo "Leak check complete. Results saved in leaks.log"
echo "Filtered out arguments: $@"

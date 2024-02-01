#!/bin/bash

# Compile the object files
gcc -c stackDriver.c
gcc -c stack_array.c

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Link the object files into a single executable
    gcc -o runStackWithArray stackDriver.o stack_array.o

    # Check if the linking was successful
    if [ $? -eq 0 ]; then
        # Run the program
        ./runStackWithArray
    else
        echo "Linking failed."
    fi
else
    echo "Compilation failed."
fi

# Clean up the object files and executable
rm -f *.o runStackWithArray
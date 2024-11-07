#!/bin/bash

# Check that there are exactly 5 .cpp files in the current directory
CPP_FILES=(*.cpp)
if [ ${#CPP_FILES[@]} -ne 7 ]; then
    echo "Error: There must be exactly 7 .cpp files in the current directory."
    exit 1
fi

# Loop over each .cpp file, compile, and run
for cpp_file in "${CPP_FILES[@]}"; do
    # Extract the base name without the extension
    base_name="${cpp_file%.cpp}"
    
    # Compile the .cpp file
    g++ "$cpp_file" -o "$base_name"
    
    # Check if the compilation succeeded
    if [ $? -eq 0 ]; then
        echo "Running $base_name..."
        ./"$base_name"
        echo "Finished running $base_name."
    else
        echo "Error: Compilation failed for $cpp_file."
        exit 1
    fi
done

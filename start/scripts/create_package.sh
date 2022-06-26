#!/bin/bash

# Build & Run unit tests & create conan package
conan create . 

# Install conan package
mkdir run_linux
cd run_linux
conan install start/0.1.0@ -g virtualrunenv 

# Start testing conan package
source activate_run.sh

# Print help message
Start -h 

# Create a start
Start --create --width 10

# Remain CLI open to play more with it
bash

# Exit or finish testing conan package 
# source deactivate_run.sh
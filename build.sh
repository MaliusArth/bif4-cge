#!/bin/bash

FOLDER=build/
EXE_PATH="${FOLDER}src/bif4-cge"

# builds the program
function build {
    if [ ! -d "$FOLDER" ]; then
        mkdir $FOLDER
    fi

    cd $FOLDER 
    cmake ..
    make
    cd ..
}

# executes the program
function run {
    $EXE_PATH
}

# check for -r command to build and run program
while getopts ":r" opt; do
    case $opt in
        r)
            echo "Building and running program" >&2
            build
            run
            ;;

        \?)
            echo "Invalid option: -$OPTARG" >&2
            ;;

      esac
done

# without arguments, just build it
if [ $# -eq 0 ]; then 
    build
fi



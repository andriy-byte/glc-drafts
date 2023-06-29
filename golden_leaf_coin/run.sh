#!/bin/bash

if [ -f "$PWD/bin/linux/golden_leaf_coin" ];
then 
    cd "$PWD/bin/linux/"
    "./golden_leaf_coin"
else
    echo "executable file doesn't exist"
fi

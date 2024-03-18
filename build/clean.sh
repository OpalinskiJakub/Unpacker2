#!/bin/bash

for item in *; do
    if [[ -f "$item" && ! "$item" =~ \.sh$ ]]; then
        rm "$item"
    elif [[ -d "$item" ]]; then
        rm -r "$item"
    fi
done



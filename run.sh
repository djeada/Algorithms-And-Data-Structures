#!/bin/bash

python3 -m unittest discover -p 'test*.py'

cd src

for dir in */; do
    if [ -d "$dir" ]; then
        cd "$dir/cpp"
        pwd
        for subdir in */; do
            if [ -d "$subdir" ]; then
                cd "$subdir"
                if [ -f "CMakeLists.txt" ]; then
                    mkdir build && cd build
                    cmake .. && make
                    ctest --verbose
                    cd ..
                    rm -rf build
                fi
                cd ..
            fi
        done
        cd ../..
    fi
done

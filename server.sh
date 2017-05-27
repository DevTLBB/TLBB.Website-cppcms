#/bin/bash

cd build && rm -rf * && cmake .. && make && cd ..
cd bin && ./main -c ../config.json 2>&1

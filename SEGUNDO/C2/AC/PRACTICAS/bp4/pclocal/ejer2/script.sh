#!/bin/bash

t=1
for i in `seq 1 30`;
do
t=$((t*2))
./daxpyO3 $t 2.5
done


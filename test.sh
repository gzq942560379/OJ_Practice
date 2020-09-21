#!/bin/bash

if [ -z $1 ]; then
    echo "Usage : ./test1.sh [bin] <num>"
    exit -1
fi

bin=$1
num=$2

if [ -z $2 ]; then
    num=1
    exit -1
fi

cat in_out/in$num | $1 > in_out/out$num  && diff in_out/out$num in_out/ans$num && rm in_out/out$num
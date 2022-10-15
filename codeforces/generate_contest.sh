#!/bin/bash

if [ -e $1 ]; then
  echo "Contest $1 alread exists"
else
  mkdir $1
  cd $1

  CNT=5

  if [ $# -eq 2 ]; then
    CNT=$2
  fi

  arr=(a b c d e f g)

  for ((i=0;i<$CNT;i++))
  do
    var=$(expr $i + 97)
    touch ${arr[i]}.cpp
    cat ../temp.cpp > ${arr[i]}.cpp
  done
fi
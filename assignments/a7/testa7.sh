#!/bin/bash

run=./a7a

suffix=$1

prefix=./tests/a7_

if [ ! -x $run ]
then
  echo "Error - cannot run '$run' (bad command or filename)"
  exit
fi

numTests=`ls ${prefix}testInput*$suffix.txt | wc -w`

for i in `seq 1 $numTests`
do
  if [ ! -f ${prefix}testInput$i$suffix.txt ]
  then
    echo "Error - cannot open ${prefix}testInput$i$suffix.txt"
    exit
  fi

  if [ ! -f ${prefix}correctOutput_a$i$suffix.txt ]
  then
    echo "Error - cannot open ${prefix}correctOutput_a$i$suffix.txt"
    exit
  fi

  if [ ! -f ${prefix}correctOutput_r$i$suffix.txt ]
  then
    echo "Error - cannot open ${prefix}correctOutput_r$i$suffix.txt"
    exit
  fi

  if [ ! -f ${prefix}correctOutput_c$i$suffix.txt ]
  then
    echo "Error - cannot open ${prefix}correctOutput_c$i$suffix.txt"
    exit
  fi

  ./$run a < ${prefix}testInput$i$suffix.txt > ${prefix}testOutput_a$i$suffix.txt
  if diff ${prefix}testOutput_a$i$suffix.txt ${prefix}correctOutput_a$i$suffix.txt > /dev/null
  then
    echo Test $i passed for alphabetical sort
    rm ${prefix}testOutput_a$i$suffix.txt
  else
    echo ***Test $i failed for alphabetical sort! See ${prefix}diff_a$i$suffix.txt for differences
    diff ${prefix}testOutput_a$i$suffix.txt ${prefix}correctOutput_a$i$suffix.txt > ${prefix}diff_a$i$suffix.txt
  fi

  ./$run r < ${prefix}testInput$i$suffix.txt > ${prefix}testOutput_r$i$suffix.txt
  if diff ${prefix}testOutput_r$i$suffix.txt ${prefix}correctOutput_r$i$suffix.txt > /dev/null
  then
    echo Test $i passed for reverse alphabetical sort
    rm ${prefix}testOutput_r$i$suffix.txt
  else
    echo ***Test $i failed for reverse alphabetical sort! See ${prefix}diff_r$i$suffix.txt for differences
    diff ${prefix}testOutput_r$i$suffix.txt ${prefix}correctOutput_r$i$suffix.txt > ${prefix}diff_r$i$suffix.txt
  fi

  ./$run c < ${prefix}testInput$i$suffix.txt > ${prefix}testOutput_c$i$suffix.txt
  if diff ${prefix}testOutput_c$i$suffix.txt ${prefix}correctOutput_c$i$suffix.txt > /dev/null
  then
    echo Test $i passed for count sort
    rm ${prefix}testOutput_c$i$suffix.txt
  else
    echo ***Test $i failed for count sort! See ${prefix}diff_c$i$suffix.txt for differences
    diff ${prefix}testOutput_c$i$suffix.txt ${prefix}correctOutput_c$i$suffix.txt > ${prefix}diff_c$i$suffix.txt
  fi
  echo
done


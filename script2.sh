#!/bin/bash

a=0
b=1
c=0
echo $a
echo $b
for ((i=1; i<10; i++))
do
	c=$((a+b))
	echo $c
	a=$b
	b=$c
done

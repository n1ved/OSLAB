#!/bin/bash
read -p "Enter Number : " num
fvar=1
while [ $num -gt 1 ]
do
	fvar=$((fvar * num))
	num=$((num - 1))
done
echo $fvar

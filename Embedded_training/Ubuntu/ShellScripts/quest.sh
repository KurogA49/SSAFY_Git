#! /bin/bash

read a

if [ $a -lt 30 ] && [ $a -gt 10 ] ;then
	echo "good"
elif [ $a -lt 50 ] && [ $a -gt 40 ] ;then
	echo "omg"
else
	echo "wow"
fi

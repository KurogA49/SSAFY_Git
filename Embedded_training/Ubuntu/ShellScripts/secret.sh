#! /bin/bash

id=$1
passwd=$2

if [ $id = "KFC" ] && [ $passwd = "1234" ] ;then
	touch ./kfc.txt
	echo "I love my eye" > ./kfc.txt
	cat ./kfc.txt
	cat ./kfc.txt
	cat ./kfc.txt
	sleep 1
	clear
	echo "keep secret, BYE"
	rm ./kfc.txt
fi

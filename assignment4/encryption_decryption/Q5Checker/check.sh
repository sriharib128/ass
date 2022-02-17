#!/bin/bash

echo Compiling encrypt.c

if gcc encrypt.c -Wall -lm -o a.t
then
	echo -e "\033[0;32mCompilation Successful :)\033[0m"
else
	echo -e "\033[0;31mCompilation Unsuccessful :(\033[0m"
	exit 1
fi

echo Running Test 1

echo -n tichnas > msg.t

./a.t msg.t key.t encrypted.t > temp.t
./decrypt.t key.t encrypted.t out.t > temp.t

if [[ "$( diff msg.t out.t )" || $(wc -l < key.t) -ne 0 || $(wc -w < key.t) -ne 1 || $(wc -c < key.t) -ne 127  ]]
then
  echo -e "\033[0;34mFailed\033[0m"
else
  echo -e "\033[0;32mPassed\033[0m"
fi

echo Running Test 2

echo -n "You were not supposed to see this. Well, now that you've come here, maybe try to play around with this code and explore bash also? It's truly amazing how you can write scripts for almost any task (learn from here: https://bfy.tw/SUfa)." > msg.t

./a.t msg.t key.t encrypted.t > temp.t
./decrypt.t key.t encrypted.t out.t > temp.t

if [ "$( diff msg.t out.t )" ]
then
  echo -e "\033[0;34mFailed\033[0m"
else
  echo -e "\033[0;32mPassed\033[0m"
fi

rm a.t msg.t key.t encrypted.t out.t temp.t

######################


echo Compiling decrypt.c

if gcc decrypt.c -Wall -lm -o a.t
then
	echo -e "\033[0;32mCompilation Successful :)\033[0m"
else
	echo -e "\033[0;31mCompilation Unsuccessful :(\033[0m"
	exit 1
fi

echo Running Test 1

echo -n tichnas > msg.t

./encrypt.t msg.t key.t encrypted.t > temp.t
./a.t key.t encrypted.t out.t > temp.t

if [[ "$( diff msg.t out.t )" || $(wc -l < key.t) -ne 0 || $(wc -w < key.t) -ne 1 || $(wc -c < key.t) -ne 127  ]]
then
  echo -e "\033[0;34mFailed\033[0m"
else
  echo -e "\033[0;32mPassed\033[0m"
fi

echo Running Test 2

echo -n "You were not supposed to see this. Well, now that you've come here, maybe try to play around with this code and explore bash also? It's truly amazing how you can write scripts for almost any task (learn from here: https://bfy.tw/SUfa)." > msg.t

./encrypt.t msg.t key.t encrypted.t > temp.t
./a.t key.t encrypted.t out.t > temp.t

if [ "$( diff msg.t out.t )" ]
then
  echo -e "\033[0;34mFailed\033[0m"
else
  echo -e "\033[0;32mPassed\033[0m"
fi

rm a.t msg.t key.t encrypted.t out.t temp.t



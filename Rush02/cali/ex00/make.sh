#!/bin/sh
make clean && make re && make clean
times=3
while (($times > 0))
do 
	number=$RANDOM
	factor=$RANDOM
	if ((($times % 2) == 0))
	then
		number=$(( number*factor ))
	else
		number=$(( number ))
	fi
	echo "\n"
	echo "=== " $number " ===" && echo "English : " && ./rush-02 $number
	echo "Italiano : " && ./rush-02 numbers.it.dict $number
	echo "Elon Musk : " && ./rush-02 numbers.alien.dict $number
	times=$(( times-1 ))
done
echo ========MADE BY CALIDE_N©=========

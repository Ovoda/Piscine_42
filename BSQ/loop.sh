#!/bin/sh
make re
max=1000
for i in `seq 2 $max`
do
	./bsq test/tables/test_vert2.txt > mymap
	if cmp -s mymap truemap
	then
		echo "The files match $i"
	else
		echo "The files are different $i"
	fi
done

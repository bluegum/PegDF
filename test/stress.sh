#!/bin/sh
usage="sress.sh directory"
[ $# -lt 1 ] && echo "$usage" && exit 1
echo $0 $1
for i in $1/*.pdf
do
    if [ -f $i ]
    then
	echo "\033[32mTesting $i";
	echo "\033[0m"
	readpdf $i
	if [ $? != 0 ]
	then
	    echo "\033[31m $i Failed!"
	else
	    echo "\033[35m $i Passed!"
	fi
    fi
done
echo "\033[0m"
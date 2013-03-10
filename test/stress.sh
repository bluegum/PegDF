#!/bin/bash
usage="sress.sh directory"
[ $# -lt 1 ] && echo "$usage" && exit 1
echo $0 $1
SAVEIFS=$IFS
#IFS=$(echo -en "\n\b")
i=0
allfiles=( )
allstat=( )
for file in $1/*.pdf
do
    ff=${file// /\\ }
    echo $ff
    if [ -f "$ff" ]
    then
	allfiles[$i]=\"$file\"
	echo "\033[32mTesting $file";
	echo "\033[0m"
	readpdf "$ff"
	if [ $? != 0 ]
	then
	    allstat[$i]=1
	    echo "\033[31m $file Failed!"
	else
	    allstat[$i]=0
	    echo "\033[35m $file Passed!"
	fi
	i=`expr $i + 1`
    fi
done
echo "\033[0m"
#echo ${allstat[@]}
tput bold
i=`expr $i - 1`
for x in `seq 0 $i`
do
    echo -n ${allfiles[$x]} ':: '
    if [[ ${allstat[$x]} == '0' ]]
    then
	echo PASSED
    else
	echo FAILED
    fi
done
tput sgr0
IFS=$SAVEIFS
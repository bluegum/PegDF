#!/bin/bash
usage="sress.sh directory"
[ $# -lt 1 ] && echo "$usage" && exit 1
echo $0 $1
SAVEIFS=$IFS
#IFS=$(echo -en "\n\b")
i=0
allfiles=( )
allstat=( )

READPDF=readpdf
if [ -f bin/readpdf ] ; then READPDF=bin/readpdf; fi

for file in $1/*.pdf
do
    ff=${file}
    if [[ -e "${ff}" ]]
    then
	    allfiles[$i]=\"$file\"
	    echo "Testing $file";
	    ${READPDF} "$ff"
	    if [ $? != 0 ]
	    then
	        allstat[$i]=1
	        echo -e "\033[0;31m $file Failed!"
	    else
	        allstat[$i]=0
	        echo -e "\033[0;32m $file Passed!"
	    fi
        echo -e "\033[0;37m"
	    i=`expr $i + 1`
    fi
done
#echo ${allstat[@]}
tput bold
i=`expr $i - 1`
for x in `seq 0 $i`
do
    echo -en "\033[1;37m"
    echo -n ${allfiles[$x]} ':: '
    if [[ ${allstat[$x]} == '0' ]]
    then
	    echo -e "\033[1;32m PASSED!\033[0;37m"
    else
	    echo -e "\033[1;31m FAILED!\033[0;37m"
    fi
done
tput sgr0
IFS=$SAVEIFS

#!/bin/sh
usage="Usage: pdfpick.sh page\# in.pdf out.pdf"
[ $# -lt 3 ] && echo "$usage" && exit 1
case "$1" in
    [0-9] )   echo \"picking page\# $1\" ;;
    [0-9][0-9] )   echo \"picking page\# $1\" ;;
    [0-9][0-9][0-9] )   echo \"picking page\# $1\" ;;
    [0-9][0-9][0-9][0-9] )   echo \"picking page\# $1\" ;;
    [0-9][0-9][0-9][0-9][0-9] )   echo \"picking page\# $1\" ;;
    *)   echo "$usage" && exit 2 ;;
esac
! [ -e $2 ] &&  echo Error: file \""$2"\" not found &&  exit 3
readpdf -x $1 $2 $3

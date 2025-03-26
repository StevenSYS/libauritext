#!/bin/bash
# $1 = Input Font Directory
# $2 = Output Font Sheet

# Example: "./makeFontSheet.sh OutFont OutFont.png"

if [ -z $1 ]; then
	echo "Missing input font directory"
	exit
fi

if [ -z $2 ]; then
	echo "Missing output font sheet"
	exit
fi

magick "$1/Specials/1/*.png" "$1/Numbers/*.png" "$1/Specials/2/*.png" "$1/Letters/Upper/*.png" "$1/Specials/3/*.png" "$1/Letters/Lower/*.png" "$1/Specials/4/*.png" -define png:include-chunk=none +append "$2"
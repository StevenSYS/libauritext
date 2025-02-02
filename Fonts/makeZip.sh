#!/bin/bash
# $1 = Output Zip File (Optional)
# $2 = Output Temp Directory (Optional)
# $3 = Info Text File (Optional)

if [ -n "$1" ]; then
	outputZip="$1"
else
	outputZip="Fonts.zip"
fi

if [ -n "$2" ]; then
	tempDir="$2"
else
	tempDir="Fonts"
fi

if [ -e "$tempDir/" ]; then
	rm -rf "$tempDir/"
fi

mkdir "$tempDir"

if [ -e "$outputZip" ]; then
	rm "$outputZip"
fi

if [ -n "$3" ] && [ -e "$3" ]; then
	cp "$3" "$tempDir/Info.txt"
fi

for i in */; do
	if [[ "${i%/}" != "$tempDir" ]]; then
		./makeFontSheet.sh "${i%/}" "$tempDir/${i%/}.png"
	fi
done

7za a -mx9 "$outputZip" "$tempDir/"
if [ -e "$tempDir" ]; then
	rm -rf "$tempDir/"
fi
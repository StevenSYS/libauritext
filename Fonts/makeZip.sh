#!/bin/bash
# $1 = Output Zip File (Optional)
# $2 = Output Directory (Optional)
# $3 = Info Text File (Optional)
if [ -e "$1" ]; then
	outputZip="$1"
else
	outputZip="Fonts.zip"
fi

if [ -e "$2" ]; then
	outputDir="$2"
else
	outputDir="Fonts"
fi

if [ -e "$outputDir/" ]; then
	rm -rf "$outputDir/"
fi
mkdir "$outputDir"

if [ -e "$outputZip" ]; then
	rm "$outputZip"
fi

if [ -e "$3" ]; then
	cp "$3" "$outputDir/Info.txt"
fi

for i in */; do
	./makeFontSheet.sh "$i" "$outputDir/${i%/}.png"
done

7za a -mx9 "$outputZip" "$outputDir/"
rm -rf "$outputDir/"
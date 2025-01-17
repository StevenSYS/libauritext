#!/bin/bash
outputDir="Fonts"
outputZip="Fonts.zip"

if [ -e $outputDir/ ]; then
	rm -rf $outputDir/
fi
mkdir $outputDir

if [ -e $outputZip ]; then
	rm $outputZip
fi

echo -e "\"These fonts are both public-domain, feel free to do whatever you want with them.\" - StevenSYS" > "$outputDir/README.txt"

for i in */; do
	./makeFontSheet.sh "$i" "$outputDir/${i%/}.png"
done

7za a -mx9 $outputZip $outputDir/
rm -rf $outputDir/
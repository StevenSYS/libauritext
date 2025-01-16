#!/bin/bash
# $1 = Input Font Directory
# $2 = Output Font Sheet

# "./makeFontSheet.sh OutFont OutFont.png" to make the OutFont
# "./makeFontSheet.sh InFont InFont.png" to make the InFont

magick $1/Specials/1/*.png $1/Numbers/*.png $1/Specials/2/*.png $1/Letters/Upper/*.png $1/Specials/3/*.png $1/Letters/Lower/*.png $1/Specials/4/*.png +append $2
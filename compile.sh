cd design || exit
clear
#grit tiles.png -gt -gB4 -Mw 2 -Mh 2 -o../gfx/tiles
#grit characters/Tann.png -gt -gB4 -Mw 2 -Mh 2 -o../gfx/tann
#grit bullets.png -gt -gB4
#grit titlescreen.png -gb -gB8
cd ..
make
#sleep 1
unameOut="$(uname -s)"
case "${unameOut}" in
    Linux*)     mgba-qt STPRPG.gba;;
    Darwin*)    open stprpg.gba -a mgba;;
    CYGWIN*)    machine=Cygwin;;
    MINGW*)     machine=MinGw;;
    *)          machine="UNKNOWN:${unameOut}"
esac

cd design || exit
clear
#grit tiles.png -gt -gB4 -Mw 2 -Mh 2 -o../gfx/tiles
#grit bullets.png -gt -gB4
#grit icons.png -gt -gB4
#grit titlescreen.png -gb -gB8
#grit winscreen.png -gb -gB8
cd ..
make
#sleep 1
open stprpg.gba -a mgba
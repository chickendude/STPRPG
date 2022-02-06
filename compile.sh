cd design || exit
clear
#grit tiles.png -gt -gB4 -Mw 2 -Mh 2 -o../gfx/tiles
#grit characters/Tann.png -gt -gB4 -Mw 2 -Mh 2 -o../gfx/tann
#grit bullets.png -gt -gB4
#grit titlescreen.png -gb -gB8
cd ..
make
#sleep 1
open stprpg.gba -a mgba
#pragma once

enum class Tile {
    BLANK,
    X,
    O
};

class TileConvertor
{
    public:
        static char to_char(Tile t)
        {
            switch(t){
                case Tile::BLANK:
                    return '-';
                case Tile::X:
                    return 'X';
                case Tile::O:
                    return '0';
            }
        }    
};
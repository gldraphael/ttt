#pragma once
#include <vector>
#include <stdexcept>

enum class Tile {
    BLANK,
    X,
    O
};

class Board {
    private:
        std::vector<std::vector<Tile>> tiles;
        
    public:
        Board()
            :tiles(3, std::vector<Tile>(3, Tile::BLANK))
        {
            
        }
        
        void set_tile(int x, int y, Tile t)
        {
            if(t == Tile::BLANK)
                throw std::runtime_error("Tile cannot be set to BLANK");
        }
};

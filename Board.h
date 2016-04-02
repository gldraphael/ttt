#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

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
        
        void print()
        {
            for(auto i : tiles)
            {
                for(auto j : i)
                {
                    std::cout << static_cast<int>(j) << "\t";
                }
                std::cout << std::endl;
            } 
        }
};

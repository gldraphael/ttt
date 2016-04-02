#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Tile.h"

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
                tiles[y][x] = t;
        }
        
        void print()
        {
            int position = 1;
            for(auto i : tiles)
            {
                for(auto j : i)
                {
                    if(j == Tile::BLANK)
                        std::cout << position << "\t";
                    else
                        std::cout << TileConvertor::to_char(j) << "\t";
                    position ++;
                }
                std::cout << std::endl;
            } 
        }
        
        bool is_full()
        {
            for(auto i:tiles)
                for(auto j:i)
                    if(j == Tile::BLANK)
                        return false;
            return true;
        }
};

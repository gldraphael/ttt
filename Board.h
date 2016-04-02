#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Tile.h"
#include "util.h"

class Board {
    private:
        std::vector<std::vector<Tile>> tiles;
        int lastx = -1, lasty = -1;
        
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
            lastx = x;
            lasty = y;
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
        
        bool is_game_over()
        {
            // Return false if no tiles were set
            if(lastx == -1 || lasty == -1)
                return false;
                
            // check row of last set tile
            if(is_equal(tiles[lasty][0], tiles[lasty][1], tiles[lasty][2]))
                return true;

            // check column of last set tile
            if(is_equal(tiles[0][lastx], tiles[1][lastx], tiles[2][lastx]))
                return true;

            if(lastx == lasty) // and not equal to -1, that's filtered out
            {
                // check left diagonal
                if(is_equal(tiles[0][0], tiles[1][1], tiles[2][2]))
                return true;
            }
            
            if(lastx + lasty == 2)
            {
                // check right diagonal
                if(is_equal(tiles[2][0], tiles[1][1], tiles[0][2]))
                    return true;   
            }

            return false;
        }
        
        
};

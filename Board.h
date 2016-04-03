#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Tile.h"
#include "util.h"
#ifdef _WIN32
#include "windows.h"
#endif

class Board {
    private:
        std::vector<std::vector<Tile>> tiles;
        int lastx, lasty;
        
    public:
        Board()
            :tiles(3, std::vector<Tile>(3, Tile::BLANK)),
            lastx(-1),
            lasty(-1)
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
        
        #ifdef _WIN32
        
        void print()
        {
            HANDLE hConsole;
            hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
            int position = 1;
            for(auto i : tiles)
            {
                SetConsoleTextAttribute(hConsole, 0x0B);
                std::cout << "-------------" << std::endl;
                for(auto j : i)
                {
                    if(j == Tile::BLANK)
                    {
                        SetConsoleTextAttribute(hConsole, 0x0B);
                        std::cout << "| ";
                        SetConsoleTextAttribute(hConsole, 0x08);
                        std::cout << position << " ";
                    }
                    else
                    {
                        SetConsoleTextAttribute(hConsole, 0x0B);
                        std::cout << "| ";
                        char v = TileConvertor::to_char(j);
                        if(v == 'X')
                            SetConsoleTextAttribute(hConsole, 0x0E);
                        else if(v == '0')
                            SetConsoleTextAttribute(hConsole, 0x0C);
                        std::cout << v << " ";
                    }
                    position ++;
                }
                SetConsoleTextAttribute(hConsole, 0x0B);
                std::cout << "|" << std::endl;
            }
            SetConsoleTextAttribute(hConsole, 0x0B); 
            std::cout << "-------------" << std::endl;
            SetConsoleTextAttribute(hConsole, 0x0F);
        }
        #else
        
        void print()
        {
            int position = 1;
            for(auto i : tiles)
            {
                std::cout << "-------------" << std::endl;
                for(auto j : i)
                {
                    if(j == Tile::BLANK)
                        std::cout << "| " << position << " ";
                    else
                        std::cout << "| " << TileConvertor::to_char(j) << " ";
                    position ++;
                }
                std::cout << "|" << std::endl;
            } 
            std::cout << "-------------" << std::endl;
        }
        
        #endif
        
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

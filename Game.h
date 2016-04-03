#pragma once
#include <iostream>
#include <stdexcept>
#include "Board.h"

using std::cin;

class Game {
    private:
        Board b;
    
    public:
        int get_input()
        {
            int i;
            if(cin >> i)
            {
                if(i >= 1 && i <= 9)
                {
                    return i;
                }
                else {
                    std::cout << "Enter a position from 1 - 9: ";
                    return get_input();
                }
            }
            else if(cin.bad())
            {
                throw std::runtime_error("IO Error");
            }
            else if(cin.eof())
            {
                throw std::runtime_error("EOF reached");
            }
            else
            {
                std::cout << "Enter a valid position: ";
                cin.clear();
                cin.ignore();
                return get_input();
            }
        }
        
        void draw()
        {
            b.print();
        }
    
        void run()
        {
            // Initial prompt
            b.print();
            
            // Tile playerTiles[2] = { Tile::X, Tile::O };
            int currentPlayer = -1;
            
            // A typical game loop
            while(!b.is_game_over())
            {
                currentPlayer = (currentPlayer + 1) % 2;
                
                // Get input 
                int i = get_input();
                
                // Update state
                b.set_tile((i-1)%3, (i - 1)/3, static_cast<Tile>(currentPlayer+1));
                
                // Draw
                draw();
            }
            
            std::cout<<"Player "<< (currentPlayer + 1) <<" has won!"<<std::endl;
        }
};

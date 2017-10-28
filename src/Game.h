#pragma once
#include <iostream>
#include <stdexcept>
#include "Board.h"

using std::cin;

class Game {
    private:
        Board b;
        int currentPlayer;
        bool gameOver;
    
    public:
    
        Game()
            : currentPlayer(-1), gameOver(false)
        { }
    
        int get_input()
        {
            int i;
            std::cout << "P" << currentPlayer + 1 << ": ";
            if(cin >> i)
            {
                if(i >= 1 && i <= 9)
                {
                    if(b.is_tile_set((i-1)%3, (i - 1)/3))
                    {
                        std::cout << "You can\'t overwrite that! Enter another position: ";
                        return get_input();
                    }
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
            
            // A typical game loop
            while(!gameOver && !b.is_full())
            {
                currentPlayer = (currentPlayer + 1) % 2;
                
                // Get input 
                int i = get_input();
                
                // Update state
                b.set_tile((i-1)%3, (i - 1)/3, static_cast<Tile>(currentPlayer+1));
                
                // Draw
                draw();
                
                gameOver = b.is_game_over();
            }
            
            if(gameOver)
            {
                std::cout<<"Player "<< (currentPlayer + 1) <<" has won!"<<std::endl;    
            }
            else
            {
                std::cout<<"The game is draw!"<<std::endl;   
            }
        }
};

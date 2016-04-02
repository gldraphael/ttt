#pragma once
#include <iostream>
#include "Board.h"

class Game {
    private:
        Board b;
    
    public:
        int get_input()
        {
            int i;
            std::cin >> i;
            return i;
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
            while(!b.is_game_over())
            {
                // Get input 
                int i = get_input();
                
                // Update state
                b.set_tile((i-1)%3, (i - 1)/3, Tile::X);
                
                // Draw
                draw();
            }
        }
};

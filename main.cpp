#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
    cout << "Welcome to TicTacToe!" << endl;
    Board b;
    b.print();
    while(!b.is_game_over())
    {
        int i;
        cin >> i;
        b.set_tile((i-1)%3, (i - 1)/3, Tile::X);
        b.print();
    }
}

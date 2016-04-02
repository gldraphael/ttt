#include <iostream>
#include "Board.h"
using namespace std;

int main()
{
    Board b;
    while(!b.is_full())
    {
        int i;
        cin >> i;
        b.set_tile((i-1)%3, (i - 1)/3, Tile::X);
        b.print();
    }
}

# ttt

A really simple tictactoe game for the console.

I've also written one using MonoGame if you're looking for GUI: https://github.com/gldraphael/mg-ttt

## Running the program

1. Clone the repository
1. `cd` into the cloned directory and run `make`.
1. An `a.out` executable should be generated. Run it using `./a.out`.

Alternatively you may paste this in your terminal:

```bash
git clone https://github.com/gldraphael/ttt.git
cd ttt
make
./a.out
```

_Also tested on windows using MSVC. Use `cl /EHsc src/main.cpp` to build._

For windows use:

```bash
git clone https://github.com/gldraphael/ttt.git
cd ttt
cl /EHsc src/main.cpp
./main.exe
```

## Requirements

* Clang or G++ (or MSVC for windows)

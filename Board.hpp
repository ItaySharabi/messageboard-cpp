#include <iostream>
#include "Direction.hpp"

using namespace std;

namespace ariel{

    class Board{
        // private:

            // char board[100][100] = {};

        public:
            // Either create a constructor to 
            // set values for MAX_ROWS/COLS 
            // or defaultly set it to MaxValue.
            unsigned int MAX_ROWS, MAX_COLS;

            Board(/*unsigned int rows, unsigned int columns*/);
            // Board(unsigned int rows, unsigned int columns);
            void post(unsigned int row, unsigned int column, Direction d, string message);
            string read(unsigned int row, unsigned int column, Direction d, unsigned int length);
            string show();
    };
};
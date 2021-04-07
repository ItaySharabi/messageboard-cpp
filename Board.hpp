#ifndef BOARD
#define BOARD
#include <iostream>
#include "Direction.hpp"
#include <vector>
#include <string>

using namespace std;

namespace ariel{

    class Board{
        private:

        unsigned int INITIAL_SIZE = 1;
        const char underscore = '_';
        unsigned int MAX_ROWS, MAX_COLS;
        unsigned int MIN_ROWS, MIN_COLS;
        vector<vector<char>> board;

        // bool my_resize(unsigned int n, unsigned int m, Direction d, unsigned int message_length);
        
        public:
            // Either create a constructor to 
            // set values for MAX_ROWS/COLS 
            // or defaultly set it to MaxValue.
            

            Board(); // Empty Constructor
            ~Board();
            // Board(unsigned int rows, unsigned int columns);
            void post(unsigned int row, unsigned int column, Direction d, const string &message);
            string read(unsigned int row, unsigned int column, Direction d, unsigned int length);
            void show();
    };
};
#endif
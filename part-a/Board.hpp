#include <iostream>
#include "Direction.hpp"

using namespace std;

namespace ariel{

    class Board{
        private:

        
        const uint MAX_ROWS = UINT32_MAX;
        const uint MAX_COLS = UINT32_MAX;
        
        public:
            // Either create a constructor to 
            // set values for MAX_ROWS/COLS 
            // or defaultly set it to MaxValue.
            

            Board(/*unsigned int rows, unsigned int columns*/); // Empty Constructor
            ~Board();
            // Board(unsigned int rows, unsigned int columns);
            void post(unsigned int row, unsigned int column, Direction d, string message);
            string read(unsigned int row, unsigned int column, Direction d, unsigned int length);
            string show();
    };
};
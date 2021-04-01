#include "Board.hpp"
// #include <iostream>
// using namespace std;


namespace ariel{

    Board::Board(/*unsigned int rows, unsigned int columns*/) {
        cout << "New instance of Board is created!" << endl;
        // Either create a constructor to 
        // set values for MAX_ROWS/COLS 
        // or defaultly set it to MaxValue.
        
    }

    Board::~Board() {
        
    }

    string Board::show() {
        
        return "show() invoked";
    }

    void Board::post(unsigned int row, unsigned int column, Direction d, string message) {
        cout << "post() invoked" << endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {

        return "read() invoked";
    }
    


    
};
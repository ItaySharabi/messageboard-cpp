#include "Board.hpp"
// #include <iostream>
// using namespace std;


namespace ariel{

    Board::Board(/*unsigned int rows, unsigned int columns*/) {
        cout << "New instance of Board is created!" << endl;
        // Either create a constructor to 
        // set values for MAX_ROWS/COLS 
        // or defaultly set it to MaxValue.
        MAX_ROWS = MAX_COLS = INT16_MAX;
    }

    // Board::Board(unsigned int rows, unsigned int columns) {
    //     cout << "New instance of Board is created!" << endl;
        
    //     cout << "rows " << rows << endl;
    //     cout << "cols " << columns << endl;
    // }

    string Board::show() {
        cout << "show() invoked" << endl;
        return "";
    }

    void Board::post(unsigned int row, unsigned int column, Direction d, string message) {
        cout << "post() invoked" << endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {
        cout << "read() invoked" << endl;
        return "";
    }



    
};
#include "Board.hpp"
// #include <iostream>
// using namespace std;


namespace ariel{

    Board::Board() {
        cout << "New instance of Board is created!" << endl;
        MAX_ROWS = MAX_COLS = 0;
        MIN_COLS = MIN_ROWS = UINT32_MAX;

        board = vector<vector<char>>(INITIAL_SIZE, vector<char>(INITIAL_SIZE, '_'));
    }

    Board::~Board() {
        cout << "Destructor()" << endl;
    }

    void Board::show() {

        string out;

        cout << "show() " << MIN_ROWS << ", " << MAX_COLS << endl;

        for (unsigned int i = MIN_ROWS; i <= MAX_ROWS; i++) {
            for (unsigned int j = MIN_COLS; j <= MAX_COLS; j++) {
                out += board.at(i).at(j);
            }
            out += "\n";
        }

        cout << out << endl;
    }

    void Board::post(unsigned int row, unsigned int column, Direction d, const string &message) {
        cout << "post() invoked" << endl;
        cout << row << ", " << column << endl;
        // if(row < 0 || row > MAX_ROWS || column < 0 || column > MAX_COLS) return;
        if(row < MIN_ROWS) {MIN_ROWS = row;}
        // if(row > MAX_ROWS) {MAX_ROWS = row;} // resize
        if(column < MIN_COLS) {MIN_COLS = column;}
        if(column > MAX_COLS) {MAX_COLS = column;}

        cout << "post ?" <<endl;

        if(d == Direction::Horizontal) {
            for(unsigned int i = 0; i < message.size(); i++) {
                board.at(row).at(i) = message.at(i);
                cout << board.at(row).at(i) << endl;
            }
        } else {
            cout << "Implement Vertical!" << endl;

        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {

        return "read() invoked";
    }

    bool Board::resize (unsigned int i, unsigned int j, Direction d, unsigned int message_length){

        if((i < UINT32_MAX || j < UINT32_MAX) && (i > 0 && j > 0)) {
            
            if(d == Direction::Horizontal) {
                for(unsigned int k = 0; k < MAX_ROWS; k++) {
                    board.at(k).resize(i + message_length);
                }
                cout << "New #Rows: " << i + message_length << endl;
                return true;
            } else {
                board.resize(j + message_length);
                cout << "New #Cols: " << j + message_length << endl;
                return true;
            }
        }

        return false;

    }
    


    
};
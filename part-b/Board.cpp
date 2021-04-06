#include "Board.hpp"
// #include <iostream>
// using namespace std;


namespace ariel{

    Board::Board() {
        MAX_ROWS = MAX_COLS = 0;
        MIN_COLS = MIN_ROWS = UINT32_MAX;

        board = vector<vector<char>>(INITIAL_SIZE, vector<char>(INITIAL_SIZE, '_'));
    }

    Board::~Board() {
        cout << "Destructor()" << endl;
    }

    void Board::show() {

        string out;

        cout << "showing from(" << MIN_ROWS << ", " << MIN_COLS << "), (" 
        << MAX_ROWS << ", " << MAX_COLS << ")" << endl;

        for (unsigned int i = MIN_ROWS; i < MAX_ROWS; i++) {
            for (unsigned int j = MIN_COLS; j < MAX_COLS; j++) {
                char val = board.at(i).at(j);
                // if (val == '\0' || val == ' ' || val == '\n' || val == '\t') {

                out += val;

            }
            out += "\n";
        }

        cout << out << endl;
    }

    void Board::post(unsigned int row, unsigned int column, Direction d, const string &message) {
        cout << "-------Inside Post(" << row << ", "
        << column << ", " << message << ")---------------" << endl;

        unsigned int msg_size = message.size();

        if(row < MIN_ROWS) {
            MIN_ROWS = row;
            cout << "Min Row is now " << row << endl;
        }
        if(column < MIN_COLS) {
            MIN_COLS = column;
            cout << "Min Col is now " << column << endl;
        }

        if(d == Direction::Vertical) {

            if(row+msg_size >= MAX_ROWS) { // If message size or position is out of 
                // MAX_ROWS = msg_size + row;  // board frame
                // RESIZE ROW COUNT
                // cout << row + msg_size << endl;
                MAX_ROWS = row + msg_size + 1;
                // MAX_ROWS += 1;
                
                
                // post(row, column, d, message);
            } 
            if(column >= MAX_COLS) {
                    MAX_COLS = column + 1;
            }
            // else { // within current board frame
            //     // post(i, j, message)
            // }

        } else { // Direction is Horizontal
            if(column + msg_size>= MAX_COLS) {
                MAX_COLS = column + msg_size + 1;
                // MAX_COLS += 1;
                
                // post(row, column, d, message);
            }
            if(row >= MAX_ROWS) {
                    MAX_ROWS = row + 1;
            }
        }
        board.resize(MAX_ROWS /*, vector<char>()*/);

        for(unsigned int i = 0; i < MAX_ROWS; i++) {
            board.at(i).resize(MAX_COLS, '_');
            // board.resize(MAX_ROWS, vector<char>(MAX_COLS, '_'));
        }

        cout << "resized" << endl;
        cout << "board.size() = " << board.size() << ", board.at(0).size() = " << board.at(0).size() << endl;

        unsigned int index = 0;
        if (d == Direction::Horizontal) {
            cout << "Posting Horizontally on row: " << row <<  endl;
            for (unsigned int j = column; index < msg_size && j < MAX_COLS-1; j++) {
                
                board.at(row).at(j) = message.at(index++);
            }
        } else {
            cout << "Posting Vertically on column: " << column <<  endl;
            cout << "row " << row << "\t MAX_ROWS" << MAX_ROWS << endl;
            for (unsigned int i = row; index < msg_size && i < MAX_ROWS-1; i++) {
                board.at(i).at(column) = message.at(index++);
                cout << board.at(i).at(column) << ", ";
            }
        }
        cout << "---------FINISHED POST()-----------" << endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {

        string s;

        if(row < 0 || column < 0 || row >= UINT32_MAX || column >= UINT32_MAX) {
            throw "index out of bounds!";
            return "";
        } 

        if (MAX_ROWS >= UINT32_MAX || MAX_COLS >= UINT32_MAX) {

        }
        if(this->MAX_COLS < 50 && this->MAX_ROWS < 50) {
            this->show();
        }
        if(d == Direction::Horizontal) {

            for(unsigned int j = column; j < column+length; j++) {
                if(j >= MAX_COLS) {
                    s += "_";
                } else {
                    s += board.at(row).at(j);
                }
            }
            
        } else { // Reading Vertically.
            for(unsigned int i = row; i < row+length; i++) {
                if(i >= MAX_ROWS) {
                    s += "_";
                } else {
                    s += board.at(i).at(column);
                }
            }
        }
        cout << "s = " << s << endl;
        return s;
    }
   
};
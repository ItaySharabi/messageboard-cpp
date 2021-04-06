#include "Board.hpp"
// #include <iostream>
// using namespace std;


namespace ariel{

    Board::Board() {
        cout << "New instance of Board is created!" << endl;
        MAX_ROWS = MAX_COLS = 1;
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

        if(row >= INITIAL_SIZE && row < MIN_ROWS) {
            MIN_ROWS = row;
            cout << "Min Row is now " << row << endl;
        }
        if(column >= INITIAL_SIZE && column < MIN_COLS) {
            MIN_COLS = column;
            cout << "Min Col is now " << column << endl;
        }

        // if(d == Direction::Vertical) {

            if(row >= MAX_ROWS) { // If message size or position is out of 
                // MAX_ROWS = msg_size + row;  // board frame
                // RESIZE ROW COUNT
                
                MAX_ROWS = d == Direction::Vertical ? row + msg_size : row;
                MAX_ROWS += 1;
                
                // post(row, column, d, message);
            } 
            // else { // within current board frame
            //     // post(i, j, message)
            // }

        // } else { // Direction is Horizontal
            if(column >= MAX_COLS) {
                MAX_COLS = d == Direction::Horizontal ? column + msg_size : column;
                MAX_COLS += 1;
            
                // post(row, column, d, message);
            }
        // }
        board.resize(MAX_ROWS, vector<char>());

        for(int i = 0; i < MAX_ROWS; i++) {
            board.at(i).resize(MAX_COLS, '_');
            // board.resize(MAX_ROWS, vector<char>(MAX_COLS, '_'));
        }

        cout << "resized" << endl;
        cout << "board.size() = " << board.size() << ", board.at(1).size() = " << board.at(1).size() << endl;

        int index = 0;
        if (d == Direction::Horizontal) {
            cout << "Posting Horizontally on row: " << row <<  endl;
            for (int j = column; index < msg_size && j < MAX_COLS-1; j++) {
                
                board.at(row).at(j) = message.at(index++);
            }
        } else {
            cout << "Posting Vertically on column: " << column <<  endl;
            cout << "row " << row << "\t MAX_ROWS" << MAX_ROWS << endl;
            for (int i = row; index < msg_size && i < MAX_ROWS-1; i++) {
                board.at(i).at(column) = message.at(index++);
                cout << board.at(i).at(column) << ", ";
            }
        }
        cout << "---------FINISHED POST()-----------" << endl;
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {

        return "read() invoked";
    }
   
};
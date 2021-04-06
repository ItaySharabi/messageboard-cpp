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
    }

    void Board::show() {

        string out;


        for (unsigned int i = MIN_ROWS; i < MAX_ROWS; i++) {
            for (unsigned int j = MIN_COLS; j < MAX_COLS; j++) {
                char val = board.at(i).at(j);

                out += val;

            }
            out += "\n";
        }
    }

    void Board::post(unsigned int row, unsigned int column, Direction d, const string &message) {

        unsigned int msg_size = message.size();

        if(row < MIN_ROWS) {
            MIN_ROWS = row;
        }
        if(column < MIN_COLS) {
            MIN_COLS = column;
        }

        if(d == Direction::Vertical) {

            if(row+msg_size >= MAX_ROWS) { // If message size or position is out of 
                MAX_ROWS = row + msg_size + 1;

            } 
            if(column >= MAX_COLS) {
                    MAX_COLS = column + 1;
            }

        } else { // Direction is Horizontal
            if(column + msg_size>= MAX_COLS) {
                MAX_COLS = column + msg_size + 1;
            }
            if(row >= MAX_ROWS) {
                    MAX_ROWS = row + 1;
            }
        }
        board.resize(MAX_ROWS /*, vector<char>()*/);

        for(unsigned int i = 0; i < MAX_ROWS; i++) {
            board.at(i).resize(MAX_COLS, '_');
        }

        unsigned int index = 0;
        if (d == Direction::Horizontal) {
            for (unsigned int j = column; index < msg_size && j < MAX_COLS-1; j++) {
                
                board.at(row).at(j) = message.at(index++);
            }
        } else {
            for (unsigned int i = row; index < msg_size && i < MAX_ROWS-1; i++) {
                board.at(i).at(column) = message.at(index++);
            }
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction d, unsigned int length) {

        string s;

        if(row < 0 || column < 0 || row >= UINT32_MAX || column >= UINT32_MAX) {
            throw "index out of bounds!";
            return "";
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
        return s;
    }
   
};
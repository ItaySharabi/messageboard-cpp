#include "doctest.h"
#include "Board.hpp"
#include <iostream>
#include <array>

using namespace std;
using namespace ariel;

const int num_of_tests = 5*6 + 4*2; // = 38 tests.

// Assuming messageboard's frame is finite 
// and consists of 10 rows and 10 columns.
const unsigned int ROWS = 10, COLS = 10;
const array <string, 4> inputs = {"Itay", "Sharabi", "Horizontal", "Vertical"};


TEST_CASE("Test read() on an empty Board:") {

    srand((unsigned)time(NULL));

    Board empty_board;

    Direction direction = Direction::Horizontal;

    uint random_length;

    for(uint i = 0; i < ROWS/2; i++) {
        for(uint j = 0; j < COLS/2; j++) {

            // Switch direction every iteration
            if(direction == Direction::Horizontal) { 

                // Reading vertically. 
                direction = Direction::Vertical;  
                random_length = ((uint)rand()%((uint)(ROWS-i))+1);
            } else {
                // Reading Horizontally.
                direction = Direction::Horizontal;
                random_length = ((uint)rand()%((uint)(COLS-j))+1);
            }

            cout << i << ", " << j << endl;
            cout << "rand length = " << random_length << endl;
            string expected_out(random_length, '_');
            CHECK(empty_board.read(i, j, direction, random_length) == expected_out);            
        }
    }

    // string test = "TEST_POST";
    // empty_board.post(0,0,direction, test);

    // CHECK(empty_board.read(0,0,direction,test.size()) != "_");
    // CHECK(empty_board.read(0,0,direction,test.size()) == test);
}

TEST_CASE("Test post() as new posts should always be displayed first:") {

    // Reset random vars.
    srand((unsigned)time(NULL));

    Board board;
    Direction direction = Direction::Horizontal;


    // For loop checks if last posted message is returned from read().
    for(uint i = 0; i < inputs.size(); i++) {
        direction = i%2 == 0 ? Direction::Horizontal : Direction::Vertical;
        CHECK_NOTHROW(board.post(i, 0, direction, inputs.at(i)));

        CHECK(inputs.at(i) == board.read(i, 0, direction, inputs.at(i).size()));
    }

    // This section checks if a new post overrides a previous post.

    /*  This test's outcome:
        read(0,0,horizontal, 4) == 'aaaa'
        and then
        read(0,0,horizontal, 4) == 'aaab'
        aaaa_       aaab_
        _____       ___b_
        _____   ->  ___b_
        _____   ->  ___b_
        _____       _____
    */
    string message = "aaaa";
    CHECK_NOTHROW(board.post(0,0, direction, message));
    CHECK(board.read(0,0, direction, message.size()) == message);

    direction = Direction::Vertical;
    CHECK_NOTHROW(board.post(0, message.size()-1, direction, "bbbb"));

    direction = Direction::Horizontal;
    CHECK(board.read(0,0, direction, message.size()) != message);
    CHECK(board.read(0,0, direction, message.size()) == "aaab");
}


// TEST_CASE

// TEST_CASE("Test post() as new posts should override previous posts:") {

//     srand((unsigned)time(NULL));

//     Board board;
//     Direction direction = Direction::Horizontal;

//     string message = "aaaa";

//     board.post(0,0, direction, message);
//     CHECK(board.read(0,0, direction, message.size()) == message);

//     direction = Direction::Vertical;
//     board.post(0, message.size()-1, direction, "bbbb");

//     direction = Direction::Horizontal;
//     CHECK(board.read(0,0, direction, message.size()) != message);
//     CHECK(board.read(0,0, direction, message.size()) == "aaab");
// }
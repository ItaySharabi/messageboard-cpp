#include <iostream>
#include <array>
using namespace std;

namespace ariel {

    enum type {
        HAT = 0, LHAND1 = 1, LEYE = 2, NOSE = 3, REYE = 4, RHAND1 = 5, LHAND2 = 6,
        TORSO = 7, RHAND2 = 8, LHAND3 = 9, BASE = 10
    };
    const int DEC = 10;
    const int VALID_LEN = 8;
    const int NUM_ELEMENTS = 11;
    const int NUM_ITEMS = 4;

    const int index_of_nose = 1;
    const int index_of_reye = 3;
    const int index_of_torso = 6;
    const int index_of_base = 7;
    const int index_of_rightarm = 5;
    const int index_of_leftarm = 4;;
    const string S = " ";
    int f();
    string snowman(long int number);
    
    // const string presets[NUM_ELEMENTS][NUM_ITEMS] = 
    //                             {{S + "_===_", S + " ___\n .....", S + "  _\n  /_\\", S + " ___\n (_*_)"}, //HATS 0
    //                              {" ", "\\", " ", " "},   // Left hand (X1)   1
    //                              {".", "o", "O", "-"},    // Eyes             2
    //                              {",", ".", "_", " "},     //Nose             3
    //                              {".", "o", "O", "-"},    // Eyes             4
    //                              {" ", "/", " ", ""},    // Right hand Y1    5
    //                              {"<", " ", "/", " "},    // Left hand X2     6
    //                              {" : ", "] [", "> <", "   "}, // Torso       7
    //                              {">", " ", "\\", ""},    // Right hand Y2    8
    //                              {" ", " ", " ", " "},    // Left hand 3 (X3) 9
    //                              {" : ", "\" \"", "___", "   "},// Base            10
    //                                                     };
    std::array<int, 11> get_items_array(int input);
    const array<string, NUM_ITEMS> hats = {S + "_===_", S + " ___\n .....", S + "  _\n  /_\\", S + " ___\n (_*_)"};//HATS 0
    const array<string, NUM_ITEMS> left_hands1 = {" ", "\\", " ", " "};// Left hand (X1)   1
    const array<string, NUM_ITEMS> left_eyes = {".", "o", "O", "-"};   // Eyes             2
    const array<string, NUM_ITEMS> noses = {",", ".", "_", " "};        //Nose             3
    const array<string, NUM_ITEMS> right_eyes = {".", "o", "O", "-"};  // Eyes             4
    const array<string, NUM_ITEMS> right_hands1 = {" ", "/", " ", ""}; // Right hand Y1    5
    const array<string, NUM_ITEMS> left_hands2 = {"<", " ", "/", " "}; // Left hand X2     6
    const array<string, NUM_ITEMS> torsos = {" : ", "] [", "> <", "   "};   // Torso       7
    const array<string, NUM_ITEMS> right_hands2 = {">", " ", "\\", ""};// Right hand Y2    8
    const array<string, NUM_ITEMS> left_hands3 = {" ", " ", " ", " "}; // Left hand 3 (X3) 9
    const array<string, NUM_ITEMS> bases = {" : ", "\" \"", "___", "   "}; // Base        10
    bool is_valid(long int num);
}

#include "snowman.hpp"
// #include <exception>
#include <stdexcept>
using namespace std;

namespace ariel {
    int f(int i) {
        switch(i) {
            case HAT:
                return HAT;
            case index_of_nose:
                return NOSE;
            case LEYE:
                return LEYE;
            case index_of_reye:
                return REYE;
            case index_of_torso: 
                return TORSO;
            case index_of_base: 
                return BASE;
            default:
                break;
        }

        return -1;
    }

    bool is_valid(long int num) {
        string s = to_string(num);
        if (s.size() != VALID_LEN) {
            throw invalid_argument("You'r input was incorrect!\n Only 8 digits of values 1-4 are accepted.\n");
            return false;
        }

        long int k = num;
        array<int, VALID_LEN> arr = {};
        for (int i = VALID_LEN-1; i >= 0; i--) {
            
            arr.at(i) = k%DEC;
            if (arr.at(i) < 1 || arr.at(i) > 4) {
                throw out_of_range("Every digit has to be in range 1-4!\n");

                return false;
            }
            k /= DEC;            
        }
        return true;
    }

    string snowman(long int num) {     
        if(is_valid(num)) {
            std::string snow_person;
            int n = (int) num;
            array <int, NUM_ELEMENTS> items = get_items_array(n);

            // Hat part
            // snow_person.append(presets[HAT][items[HAT]] + "\n");
            snow_person.append(hats.at(items[HAT]) + "\n");

            // Face parts:

            // array<string, NUM_ITEMS> body= presets.at(LHAND1);

            // snow_person.append(presets[LHAND1][items[LHAND1]]);
            snow_person.append(left_hands1.at(items[LHAND1]));
            snow_person.append("(" + left_eyes.at(items[LEYE]));
            snow_person.append(noses.at(items[NOSE]));
            snow_person.append(right_eyes.at(items[REYE]) + ")");
            snow_person.append(right_hands1.at(items[RHAND1]) + "\n");

            //Body parts:
            snow_person.append(left_hands2.at(items[LHAND2]));
            snow_person.append("("+ torsos.at(items[TORSO])+")");
            snow_person.append(right_hands2.at(items[RHAND2]) + "\n");

            // Base parts:
            snow_person.append(left_hands3.at(items[LHAND3]));
            snow_person.append("("+bases.at(items[BASE])+")\n");
                        
            return snow_person;
        }
        return "Wrong input!\n";
    }

    array<int, NUM_ELEMENTS> get_items_array(int input) {
        array<int, VALID_LEN> input_arr = {};
        array<int, NUM_ELEMENTS> ans = {}; 

        int t = input;

        for (int i = VALID_LEN-1; i >= 0; i--) {
            input_arr.at(i) = t%DEC;
            t /= DEC;
        }
        
        for(int i  = 0; i < VALID_LEN; i++) {
            if(i == index_of_leftarm) { // if i represenets the X items (Left hand)
                    ans.at(LHAND1) = input_arr.at(i) - 1; // X1
                    ans.at(LHAND2) = input_arr.at(i) - 1; // X2
                    ans.at(LHAND3) = input_arr.at(i) - 1; // X3
            }
            else if(i == index_of_rightarm) {// if i represents the Y items (Right hand)
                ans.at(RHAND1) = input_arr.at(i) - 1; // Y1
                ans.at(RHAND2) = input_arr.at(i) - 1; // Y2
            }   
            else {
                // cout << input_arr.at(f(i)) << endl;
                ans.at(f(i)) = input_arr.at(i) - 1;
            }

        }
        
        return ans;
    }       
}


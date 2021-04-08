#include "Board.hpp"
#include "snowman.hpp"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>



// #include <stdlib.h>
// #include <time.h>
using namespace ariel;

int rand_snowman_input() {
    srand(clock()); // Reset Clock

    int i = 0;
    int num = rand()%4 + 1; 
    int k;

    while(i < 7) {
        srand(clock()); // Reset clock

        k = (rand()%4)+1;

        num *= 10;
        num += k;

        i++;
    }
    return num;
}

int main() {

    Board board;
    const Direction horiz = Direction::Horizontal;
    const Direction vert = Direction::Vertical;
    const int error_count = 5;
    string s;

    
    rand_snowman_input();

    try {
        s = snowman(123412321);

    } catch (exception e) {
        cout << e.what();
    }
    
    s = snowman(12312312);



    
    cout << "Welcome to my Dynamic Messageboard!" << endl;

    cout << "You can choose input from 1 - 4 and practice with the messageboard:" << endl;

    unsigned int user_choice = 0;

    unsigned int i, j;
    string message;
    int d;
    Direction direction;

    while(true) {
        board.show();
        cout << "1: post(i, j, Direction, Text)" << endl;    
        cout << "2: read(i, j, (Horizontal=0, Vertical=1), Length) - Get text from (i,j), 'Length' chars long" << endl;    
        cout << "3: random snowman - post a random snowman" << endl;    
        cout << "4: custom snowman(8 digits from 1-4) - post a snowman ;)" << endl; 
        cout << "5: exit - Stop the program" << endl;
        cin >> user_choice;
        switch(user_choice) {
            case 1:
                cout << "i = ";
                cin >> i;
                cout << "j = ";
                cin >> j;
                cout << "Direction: 0 - Horizontal\n\t   1 - Vertical" << endl;
                cin >> d;

                switch(d) {
                    case 1:
                        direction = Direction::Vertical;
                        break;
                    default: 
                        direction = Direction::Horizontal;
                        break;
                }
                cout << "Enter Text: \n";
                cin >> message;
                board.post(i, j, direction, message);
                continue;
            
            case 3:
                cout << "Random snowman at your request!" << endl;
                try {
                    int k = rand_snowman_input();
                    cout << k << endl;
                    board.post(0, 0, Direction::Horizontal, snowman(k));
                } catch (exception e) {
                    cout << e.what();
                }
                continue;
            case 4:
                int snow_input;
                cout << "Enter 8 digits in range 1-4" << endl;
                cin >> snow_input;
                cout << "Where do u wanna put it? (i, j)" << endl;
                cout << "i = ";cin >> i; cout << "j = "; cin >> j;
                try {
                    board.post(i, 1, horiz, snowman(snow_input));
                } catch(exception e) {
                    cout << e.what() << endl;
                }
                continue;
            case 5:
                cout << "Quitting" << endl;
                return -1;
            default:
                continue;
        }
    }





    return 0;
}


#include "Board.hpp"
#include "snowman.hpp"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#define MAX_LINE 1024


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
    int exit = 0;
    string s;
    
        
    cout << "\n\nWelcome to my Dynamic Messageboard!" << endl;

    cout << "You can choose input from 1 - 5 and practice with the messageboard:" << endl;

    unsigned int user_choice = 0;

    unsigned int i, j;
    int d;
    Direction direction;

    while(!exit) {
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
                cout << "Direction: 1 - Horizontal\n\t   2 - Vertical" << endl;
                cin >> d;

                switch(d) {
                    case 2:
                        direction = Direction::Vertical;
                        break;
                    default: 
                        direction = Direction::Horizontal;
                        break;
                }
                cout << "Enter Text: \n";
                char message[MAX_LINE];
                getchar();
                cin.getline(message, MAX_LINE);
                board.post(i, j, direction, message);
                break;
            
            case 2:
                cout << "Read text from the messageboard: " << endl;
                cout << "i = "; cin >> i; cout << "j = ";
                cout << "Direction: 1 - Horizontal\n\t   2 - Vertical" << endl;
                cin >> d;
                switch(d) {
                    case 2:
                        direction = Direction::Vertical;
                        break;
                    default: 
                        direction = Direction::Horizontal;
                        break;
                }
                int length;
                cout << "Reading length: "; cin >> length;
                try {
                    string out = board.read(i, j, direction, length);
                    cout << out;
                } catch (exception e) {
                    cout << e.what();
                }
                break;
            
            case 3:
                cout << "Random snowman at your request! Shown at (0,0)" << endl;
                try {
                    int k = rand_snowman_input();
                    cout << k << endl;
                    board.post(0, 0, Direction::Horizontal, snowman(k));
                } catch (exception e) {
                    cout << e.what();
                }
                break;
            case 4:
                int snow_input;
                cout << "Enter 8 digits in range 1-4" << endl;
                cin >> snow_input;
                cout << "Where do u wanna put it? (i, 1)" << endl;
                cout << "i = ";cin >> i;
                try {
                    board.post(i, 1, horiz, snowman(snow_input));
                } catch(exception e) {
                    cout << e.what() << endl;
                }
                continue;
            case 5:
                cout << "Quitting" << endl;
                exit = 1;
                break;
            default:
                continue;
        }
        
    }





    return 0;
}


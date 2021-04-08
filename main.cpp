#include "Board.hpp"
#include "snowman.hpp"
#include <stdlib.h>
#include <time.h>
using namespace ariel;

int main() {

    Board board;
    const Direction horiz = Direction::Horizontal;
    const Direction vert = Direction::Vertical;

    
    cout << "Welcome to my Dynamic Messageboard!" << endl;

    cout << "You can choose input from 1 - 4 and practice with the messageboard:" << endl;

     


    // board.post(0,0, Direction::Horizontal, "Hello Meitar");

    // // board.post(0,0, Direction::Vertical, "Hello Raz");
    // board.post(20,10, Direction::Horizontal, "Hello Itay");
    // // board.post(10,10, Direction::Horizontal, "Hello ");
    // // board.post(50,30, Direction::Horizontal, "Hello Meitar");
    // board.post(10,15, Direction::Vertical, "dkajdlawhf");



    // board.show();



    unsigned int user_choice = 0;

    unsigned int i, j;
    string message;
    int d;
    Direction direction;

    while(true) {
        board.show();
        cout << "1: post(i, j, Direction, Text)" << endl;    
        cout << "2: read(i, j, (Horizontal=0, Vertical=1), Length) - Get text from (i,j), 'Length' chars long" << endl;    
        cout << "3: show() - Display Board" << endl;    
        cout << "4: post_snowman(8 digits from 1-4) - post a snowman ;)" << endl; 
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

            case 4:
                int snow_input;
                cout << "Enter 8 digits in range 1-4" << endl;
                cin >> snow_input;
                cout << "Where do u wanna put it?" << endl;
                try {
                    board.post(rand()%100,rand()%100, horiz, snowman(snow_input));
                } catch(exception e) {
                    cout << e.what() << endl;
                }
                continue;
            case 5:
                cout << "Quitting" << endl;
                exit(1);
                break;
            default:
                continue;
        }
        board.show();
    }





    return 0;
}
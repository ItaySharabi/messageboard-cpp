#include "Board.hpp"
#include <stdlib.h>
#include <time.h>
using namespace ariel;

int main() {

    cout << "hello" << endl;

    Board board;

    board.show();

    board.post(2, 4, Direction::Vertical, "Hello");

    board.show();

    

    board.post(10, 10, Direction::Horizontal, "Good Bye!");

    board.show();


    board.post(5, 5, Direction::Horizontal, "And");

    board.show();

    // board.post(100, 5, Direction::Horizontal, "KLKLK");

    // board.show();

    // board.post(27, 34, Direction::Horizontal, "Hello There!");

    // board.show();
    
    board.post(1, 50, Direction::Horizontal, "ASDAUWGF");
    board.show();


    board.post(6, 25, Direction::Horizontal, "Doing well so far!");
    board.show();
    // for(int i = 1; i <= 5; i++) {

    //     srand(clock());
    //     unsigned int d = rand()%2;
    //     board.post(i, i+50, (d%2 == 0 ? Direction::Horizontal : Direction::Vertical), "KAKA");
    //     board.show();
    // }

    return 0;
}
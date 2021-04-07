#include "Board.hpp"
#include <stdlib.h>
#include <time.h>
using namespace ariel;

int main() {

    cout << "hello" << endl;

    Board board;


    board.post(0, 0, Direction::Horizontal, "Hello");

    board.show();

    board.post(2, 4, Direction::Vertical, "Hello");

    board.show();

    

    board.post(10, 10, Direction::Horizontal, "Good Bye!");

    board.show();

    return 0;
}
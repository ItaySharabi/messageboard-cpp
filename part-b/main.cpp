#include "Board.hpp"
using namespace ariel;

int main() {

    cout << "hello" << endl;

    Board board;
    board.post(1,3, Direction::Horizontal, "Hello!");

    board.show();

    return 0;
}
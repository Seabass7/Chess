#include "Headers.h"

int main(void) {
	Board* board = new Board();
	board->draw();
	board->move(Position(1, 7), Position(3, 6));
	board->draw();
	board->move(Position(3, 7), Position(2, 6));
	board->draw();
	board->move(Position(2, 6), Position(2, 7));
	board->draw();
	board->move(Position(1, 6), Position(1, 7));
	board->draw();
	board->move(Position(2, 7), Position(1, 6));
	board->draw();
	board->move(Position(1, 6), Position(5, 2));
	board->draw();
	board->move(Position(1, 7), Position(1, 8));
	board->draw();
	board->move(Position(1, 6), Position(5, 2));
	board->draw();
	board->move(Position(5, 2), Position(7, 4));
	board->draw();
	char c;
	std::cin >> c;
	return 0;
}
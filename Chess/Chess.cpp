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
	board->move(Position(1, 8), Position(1, 9));
	board->draw();
	board->move(Position(1, 6), Position(5, 2));
	board->draw();
	board->move(Position(5, 2), Position(7, 4));
	board->draw();
	board->move(Position(2, 1), Position(2, 4));
	board->draw();
	board->move(Position(2, 4), Position(7, 4));
	board->draw();
	board->move(Position(7, 4), Position(8, 4));
	board->draw();
	board->move(Position(1, 8), Position(1, 9));
	board->draw();
	board->move(Position(8, 4), Position(9, 4));
	board->draw();
	board->move(Position(1, 1), Position(2, 2));
	board->draw();
	board->move(Position(2, 2), Position(5, 4));
	board->draw();
	board->move(Position(2, 2), Position(2, 6));
	board->draw();
	char c;
	std::cin >> c;
	return 0;
}
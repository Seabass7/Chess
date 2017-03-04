#include "Headers.h"

Board::Board()
{
	pieces.push_back(new Pawn(0, Position(1, 7)));
	pieces.push_back(new Pawn(0, Position(2, 7)));
	pieces.push_back(new Pawn(0, Position(3, 7)));
	pieces.push_back(new Pawn(1, Position(2, 6)));
	pieces.push_back(new Pawn(1, Position(1, 6)));
	pieces.push_back(new Pawn(1, Position(3, 6)));
}

Board::~Board()
{
}

void Board::draw()
{
	bool drawn;
	for (int i = 1; i <= 8; i++) {
		std::cout << std::endl << "-------------------------------" << std::endl;
		for (int j = 1; j <= 8; j++) {
			std::cout << " | ";
			drawn = false;
			for each (Pieces* piece in pieces)
			{
				if (piece->getPosition() == Position(j, i)) {
					piece->draw();
					drawn = true;
					break;
				}
			}
			if (!drawn) {
				std::cout << "   ";
			}
		}
		std::cout << " | ";
	}
	std::cout << "-------------------------------" << std::endl;
	std::cout << std::endl;
}

bool Board::move(const Position& position, const Position& destination)
{
	for each (Pieces* piece in pieces)
	{
		if (piece->getPosition() == position)
			if (piece->move(player, pieces, destination))
				player = !player;
	}
	return false;
}

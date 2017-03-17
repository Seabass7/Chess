#include "Headers.h"

Board::Board() //TODO
{
	pieces.push_back(new Pawn(1, Position(2, 6)));
	pieces.push_back(new Pawn(1, Position(1, 6)));
	pieces.push_back(new Pawn(1, Position(3, 6)));
	pieces.push_back(new Pawn(1, Position(5, 2)));
	pieces.push_back(new Knight(0, Position(1, 7)));
	pieces.push_back(new Bishop(0, Position(2, 7)));
	pieces.push_back(new Pawn(0, Position(3, 7)));
	pieces.push_back(new Rook(1, Position(2, 1)));
	pieces.push_back(new Queen(0, Position(1, 1)));
	pieces.push_back(new King(0, Position(4, 1)));
}

Board::~Board() //TODO
{
}

void Board::draw() //TODO
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

	//for each (History* hist in history) {
	//	std::cout << "piece" << hist->getPosition().x << "," << hist->getPosition().y << " - ";
	//	if (hist->getRemovedPiece() != nullptr)
	//		hist->getRemovedPiece()->draw();
	//	std::cout << std::endl;
	//}
	
}

bool Board::move(const Position& position, const Position& destination)
{
	Pieces* garbage = new Pawn(0, Position(9,9));
	for each (Pieces* piece in pieces)
	{
		if (piece->getPosition() == position) { //Check for player (&& player == owner)
			if (destination.isValid() && piece->move(player, pieces, destination, &garbage)) {
				player = !player;
				if (garbage->getPosition() == Position(9, 9)) {
					delete(garbage);
					history.push_back(new History(position, destination, nullptr));
				} else {
					remove(garbage);
					history.push_back(new History(position, destination, garbage));
				}
				return true;
			} else {
				std::cout << "Invalid move." << std::endl;
			}
		}
	}
	return false;
}

void Board::remove(Pieces * piece)
{
	sideBoard.push_back(piece);
	std::vector<Pieces*>::iterator position = std::find(pieces.begin(), pieces.end(), piece);
	if (position != pieces.end())
		pieces.erase(position);
}

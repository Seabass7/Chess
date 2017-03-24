#include "Headers.h"

Board::Board() //TODO
{
	//White
	//Pawns
	pieces.push_back(new Pawn(0, Position(0, 6)));
	pieces.push_back(new Pawn(0, Position(1, 6)));
	pieces.push_back(new Pawn(0, Position(2, 6)));
	pieces.push_back(new Pawn(0, Position(3, 6)));
	pieces.push_back(new Pawn(0, Position(4, 6)));
	pieces.push_back(new Pawn(0, Position(5, 6)));
	pieces.push_back(new Pawn(0, Position(6, 6)));
	pieces.push_back(new Pawn(0, Position(7, 6)));
	//Rooks
	pieces.push_back(new Rook(0, Position(0, 7)));
	pieces.push_back(new Rook(0, Position(7, 7)));
	//Knights
	pieces.push_back(new Knight(0, Position(1, 7)));
	pieces.push_back(new Knight(0, Position(6, 7)));
	//Bishops
	pieces.push_back(new Bishop(0, Position(2, 7)));
	pieces.push_back(new Bishop(0, Position(5, 7)));
	//King
	pieces.push_back(new King(0, Position(3, 7)));
	//Queen
	pieces.push_back(new Queen(0, Position(4, 7)));

	//Black
	//Pawns
	pieces.push_back(new Pawn(1, Position(0, 1)));
	pieces.push_back(new Pawn(1, Position(1, 1)));
	pieces.push_back(new Pawn(1, Position(2, 1)));
	pieces.push_back(new Pawn(1, Position(3, 1)));
	pieces.push_back(new Pawn(1, Position(4, 1)));
	pieces.push_back(new Pawn(1, Position(5, 1)));
	pieces.push_back(new Pawn(1, Position(6, 1)));
	pieces.push_back(new Pawn(1, Position(7, 1)));
	//Rooks
	pieces.push_back(new Rook(1, Position(0, 0)));
	pieces.push_back(new Rook(1, Position(7, 0)));
	//Knights
	pieces.push_back(new Knight(1, Position(1, 0)));
	pieces.push_back(new Knight(1, Position(6, 0)));
	//Bishops
	pieces.push_back(new Bishop(1, Position(2, 0)));
	pieces.push_back(new Bishop(1, Position(5, 0)));
	//King
	pieces.push_back(new King(1, Position(3, 0)));
	//Queen
	pieces.push_back(new Queen(1, Position(4, 0)));

	//pieces.push_back(new Knight(0, Position(1, 7)));
	//pieces.push_back(new Bishop(0, Position(2, 7)));
	//pieces.push_back(new Rook(1, Position(2, 1)));
	//pieces.push_back(new Queen(0, Position(1, 1)));
	//pieces.push_back(new King(0, Position(4, 1)));
}

Board::~Board() //TODO
{
}

void Board::draw(sf::RenderWindow& window, const Position& selected) //TODO
{
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			for each (Pieces* piece in pieces)
			{
				if (piece->getPosition() == Position(x, y)) {
					if (selected == Position(x, y) && piece->getOwner() == player) {
						sf::RectangleShape current(sf::Vector2f(TILESIZE - 4, TILESIZE - 4));
						current.setPosition(x * TILESIZE + 2, y * TILESIZE + 2);
						current.setFillColor(sf::Color::Magenta);
						window.draw(current);
					}
					piece->draw(window);
					break;
				}
			}
		}
	}

	//for each (History* hist in history) {
	//	std::cout << "piece" << hist->getPosition().x << "," << hist->getPosition().y << " - ";
	//	if (hist->getRemovedPiece() != nullptr)
	//		hist->getRemovedPiece()->draw();
	//	std::cout << std::endl;
	//}
	
}

bool Board::move(const Position& position, const Position& destination)
{
	Pieces* garbage = nullptr;
	for each (Pieces* piece in pieces)
	{
		if (piece->getPosition() == position && player == piece->getOwner()) {
			if (destination.isValid() && piece->move(player, pieces, destination, &garbage)) {
				player = !player;
				if (garbage == nullptr) {
					history.push_back(new History(position, destination, nullptr));
				} else {
					remove(garbage);
					history.push_back(new History(position, destination, garbage));
				}
				piece->stats(); //Add more?
				return true;
			} else {
				std::cout << "Invalid move." << std::endl;
			}
		}
	}
	return false;
}

bool Board::validPiece(const Position & position)
{
	for each (Pieces* piece in pieces)
	{
		if (piece->getPosition() == position) {
			if (piece->getOwner() == player)
				return true;
			else
				return false;
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

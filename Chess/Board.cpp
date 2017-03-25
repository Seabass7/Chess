#include "Headers.h"

Board::Board()
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
	pieces.push_back(new King(0, Position(4, 7)));
	//Queen
	pieces.push_back(new Queen(0, Position(3, 7)));

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
	pieces.push_back(new King(1, Position(4, 0)));
	//Queen
	pieces.push_back(new Queen(1, Position(3, 0)));
}

Board::~Board() //TODO
{
}

void Board::draw(sf::RenderWindow& window, const Position& selected, const sf::View& boardView, const sf::View& backView) //TODO
{
	window.setView(boardView);
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			for each (Pieces* piece in pieces)
			{
				if (piece->getPosition() == Position(x, y)) {
					if (selected == Position(x, y) && piece->getOwner() == player) {
						sf::RectangleShape current(sf::Vector2f(TILESIZE - 4.f, TILESIZE - 4.f));
						current.setPosition(x * TILESIZE + 2.f, y * TILESIZE + 2.f);
						current.setFillColor(sf::Color::Magenta);
						window.draw(current);
					}
					piece->draw(window);
					break;
				}
			}
		}
	}

	window.setView(backView);
	int p0 = 0, p1 = 0;
	for each (History* item in history) {
		if (item->getRemovedPiece() != nullptr) {
			if (item->getRemovedPiece()->getOwner() == 1) {
				item->getRemovedPiece()->drawSide(window, p1%8, p1/8);
				p1++;
			} else {
				item->getRemovedPiece()->drawSide(window, p0%8, p0/8 + 2);
				p0++;
			}
		}
	}
}

bool Board::move(const Position& position, const Position& destination)
{
	Pieces* garbage = nullptr;
	for each (Pieces* piece in pieces)
	{
		if (piece->getPosition() == position && player == piece->getOwner()) {
			if (destination.isValid() && piece->move(player, pieces, history, destination, &garbage)) {
				if (piece->getType() == Pieces::Pawn && (piece->getPosition().y == 7 || piece->getPosition().y == 0)) {
					remove(piece);
					pieces.push_back(new ::Queen(player, piece->getPosition())); //TODO: Choose piece
				}
				if (garbage == nullptr) {
					history.push_back(new History(position, destination, nullptr));
				} else {
					remove(garbage);
					history.push_back(new History(position, destination, garbage));
				}
				piece->stats(garbage);
				player = !player;
				return true;
			} else {
				std::cout << "Invalid move." << std::endl;
			}
		}
	}
	return false;
}

bool Board::gameOver()
{
	Pieces* garbage = nullptr;
	for each (Pieces* piece in pieces) {
		if (piece->getOwner() == player) {
			for (int y = 0; y < 8; y++) {
				for (int x = 0; x < 8; x++) {
					if (piece->testMove(player, pieces, history, Position(x, y), &garbage)) {
						return false;
					}
				}
			}
		}
	}
	return true;
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

bool Board::checkLast(Pieces * piece)
{
	if (history.at(0)->getDestination() == piece->getPosition())
		return true;
	return false;
}



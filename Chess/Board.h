#pragma once

class Board {
private:
	std::vector<Pieces*> pieces;
	std::vector<Pieces*> sideBoard; //TODO
	std::vector<History*> history; //TODO
	bool player;
public:
	Board();
	~Board();
	void Board::draw(sf::RenderWindow& window, const Position& selected);
	bool move(const Position& position, const Position& destination);
	bool validPiece(const Position& position);
	void remove(Pieces* piece);
	bool checkLast(Pieces* piece);
};
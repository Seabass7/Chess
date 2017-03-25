#pragma once

class Board {
private:
	std::vector<Pieces*> pieces;
	std::vector<Pieces*> sideBoard;
	std::vector<History*> history;
	bool player;
public:
	Board();
	~Board();
	void draw(sf::RenderWindow& window, const Position& selected, const sf::View& boardView, const sf::View& backView);
	bool move(const Position& position, const Position& destination);
	bool gameOver();
	bool validPiece(const Position& position);
	void remove(Pieces* piece);
	bool checkLast(Pieces* piece);
};
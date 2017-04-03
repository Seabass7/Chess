#pragma once

class Board {
private:
	std::vector<Pieces*> pieces;
	std::vector<Pieces*> sideBoard;
	std::vector<History*> history;
	bool player;
	bool running;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Board();
	~Board();
	void drawBackground(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, const Position& selected, const sf::View& boardView, const sf::View& backView);
	bool move(const Position& position, const Position& destination);
	bool gameOver();
	bool validPiece(const Position& position);
	void remove(Pieces* piece);
	bool checkLast(Pieces* piece);
};
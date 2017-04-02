#pragma once

class Pieces {
public:
	enum Type { King, Queen, Rook, Bishop, Knight, Pawn };
protected:
	Type type;
	bool owner;
	size_t moves;
	size_t taken;
	Position position;
	sf::Texture texture;
	sf::Sprite sprite;
	bool check(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage);
public:
	Pieces(Type type, bool owner, Position position) : type(type), owner(owner), moves(0), taken(0), position(position) {};
	~Pieces() {};
	bool getOwner() { return owner; };
	Type getType() { return type; };
	Position& getPosition() { return position; };
	void draw(sf::RenderWindow& window);
	void drawSide(sf::RenderWindow& window, const int x, const int y);
	bool move(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage);
	virtual bool testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage) = 0;
	void stats(Pieces* taken);
	size_t getMoves() { return moves; };
};
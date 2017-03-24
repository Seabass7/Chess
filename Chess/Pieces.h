#pragma once

class Pieces {
public:
	enum Type { King, Queen, Rook, Bishop, Knight, Pawn };
protected:
	Type type;
	bool owner;
	size_t moves;
	Position position;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Pieces(Type type, bool owner, Position position) : type(type), owner(owner), moves(0), position(position) {};
	bool getOwner() { return owner; };
	Position& getPosition() { return position; };
	void draw(sf::RenderWindow& window) {
		sprite.setPosition(position.x * TILESIZE + 18, position.y * TILESIZE - 2);
		sprite.setScale(sf::Vector2f(0.29f, 0.29f));
		window.draw(sprite);
	};
	virtual bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage) =0;
	void stats() { moves++; }; //Add more?
};
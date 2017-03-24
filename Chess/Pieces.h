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
	bool check(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position) {
		Pieces* tempGarbage;
		Position temp = this->position;
		this->position = position;
		for each (Pieces* king in board) {
			if (king->type == Pieces::King && king->getOwner() == player){
				for each (Pieces* piece in board) {
					if (piece->getOwner() != player && !(piece->getPosition() == this->position)) {
						if (piece->testMove(!player, board, history, king->getPosition(), &tempGarbage)) {
							this->position = temp;
							return true;
						}
					}
				}
			}
		}
		this->position = temp;
		return false;
	};
public:
	Pieces(Type type, bool owner, Position position) : type(type), owner(owner), moves(0), taken(0), position(position) {};
	bool getOwner() { return owner; };
	Position& getPosition() { return position; };
	void draw(sf::RenderWindow& window) {
		sprite.setPosition(position.x * TILESIZE + 18.f, position.y * TILESIZE - 2.f);
		sprite.setScale(sf::Vector2f(0.29f, 0.29f));
		window.draw(sprite);
	};
	bool move(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage) {
		if (testMove(player, board, history, position, garbage)) {
			if (!check(player, board, history, position)) {
				this->position = position;
				return true;
			}
		}
		return false;
	};
	virtual bool testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage) = 0;
	void stats(Pieces* taken) {
		moves++;
		if (taken != nullptr)
			this->taken++;
	};
	size_t getMoves() { return moves; };
};
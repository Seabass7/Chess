#pragma once

class Pieces {
public:
	enum Type { King, Queen, Rook, Bishop, Knight, Pawn };
protected:
	Type type;
	bool owner;
	Position position;
public:
	Pieces(Type type, bool owner, Position position) : type(type), owner(owner), position(position) {};
	bool getOwner() { return owner; };
	Position& getPosition() { return position; };
	virtual void draw() =0;
	virtual bool move(const bool player, const std::vector<Pieces*>& board, const Position& position) = 0;
};
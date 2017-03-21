#pragma once

class Pieces {
public:
	enum Type { King, Queen, Rook, Bishop, Knight, Pawn };
protected:
	Type type;
	bool owner;
	size_t moves;
	Position position;
public:
	Pieces(Type type, bool owner, Position position) : type(type), owner(owner), moves(0), position(position) {};
	bool getOwner() { return owner; };
	Position& getPosition() { return position; };
	virtual void draw() =0;
	virtual bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage) =0;
	void stats() { moves++; }; //Add more?
};
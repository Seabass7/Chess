#pragma once

class Position {
private:
	int x;
	int y;
public:
	Position() {};
	Position(int x, int y) : x(x), y(y) {};
	bool Position::operator==(const Position& position) const {
		return (position.x == x && position.y == y);
	}
	bool Position::operator < (const Position& position) const
	{
		if (x == position.x)
			return (y < position.y);
		return (x < position.x);
	}
	friend class Board; //TEST
	friend class Pieces;
	friend class Pawn;
	friend class Knight;
	friend class Bishop;
	friend class Rook;
	friend class Queen;
	friend class King;
};
#pragma once

class Bishop : public Pieces {
public:
	Bishop(bool owner, Position position) : Pieces(Pieces::Bishop, owner, position) {};
	~Bishop() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
#pragma once

class King : public Pieces {
public:
	King(bool owner, Position position) : Pieces(Pieces::King, owner, position) {};
	~King() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
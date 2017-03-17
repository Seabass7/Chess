#pragma once

class Rook : public Pieces {
public:
	Rook(bool owner, Position position) : Pieces(Pieces::Rook, owner, position) {};
	~Rook() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
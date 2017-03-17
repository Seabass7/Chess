#pragma once

class Queen : public Pieces {
public:
	Queen(bool owner, Position position) : Pieces(Pieces::Queen, owner, position) {};
	~Queen() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
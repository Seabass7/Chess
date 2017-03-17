#pragma once

class Knight : public Pieces {
public:
	Knight(bool owner, Position position) : Pieces(Pieces::Knight, owner, position) {};
	~Knight() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
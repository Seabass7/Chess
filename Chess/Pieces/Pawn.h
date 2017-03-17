#pragma once

class Pawn : public Pieces {
public:
	Pawn(bool owner, Position position) : Pieces(Pieces::Pawn, owner, position) {};
	~Pawn() { std::cout << "Removing pawn..."; };
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
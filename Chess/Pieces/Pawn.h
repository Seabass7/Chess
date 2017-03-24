#pragma once

class Pawn : public Pieces {
public:
	Pawn(bool owner, Position position) : Pieces(Pieces::Pawn, owner, position) {
		if (owner == 0) {
			if (!texture.loadFromFile("Textures/pawn_w.png"))
			{
				std::cout << "Error loading pawn texture white" << std::endl;
			}
		}
		else {
			if (!texture.loadFromFile("Textures/pawn_b.png"))
			{
				std::cout << "Error loading pawn texture black" << std::endl;
			}
		}
		sprite.setTexture(texture);
	};
	~Pawn() { std::cout << "Removing pawn..."; };
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
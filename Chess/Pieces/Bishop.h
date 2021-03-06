#pragma once

class Bishop : public Pieces {
public:
	Bishop(bool owner, Position position) : Pieces(Pieces::Bishop, owner, position) {
		if (owner == 0) {
			if (!texture.loadFromFile("Textures/bishop_w.png"))
			{
				std::cout << "Error loading bishop texture white" << std::endl;
			}
		}
		else {
			if (!texture.loadFromFile("Textures/bishop_b.png"))
			{
				std::cout << "Error loading bishop texture black" << std::endl;
			}
		}
		sprite.setTexture(texture);
	};
	~Bishop() {};
	bool testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage);
};
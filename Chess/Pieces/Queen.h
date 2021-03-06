#pragma once

class Queen : public Pieces {
public:
	Queen(bool owner, Position position) : Pieces(Pieces::Queen, owner, position) {
		if (owner == 0) {
			if (!texture.loadFromFile("Textures/queen_w.png"))
			{
				std::cout << "Error loading queen texture white" << std::endl;
			}
		}
		else {
			if (!texture.loadFromFile("Textures/queen_b.png"))
			{
				std::cout << "Error loading queen texture black" << std::endl;
			}
		}
		sprite.setTexture(texture);
	};
	~Queen() {};
	bool testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage);
};
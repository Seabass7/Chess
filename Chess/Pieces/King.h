#pragma once

class King : public Pieces {
public:
	King(bool owner, Position position) : Pieces(Pieces::King, owner, position) {
		if (owner == 0) {
			if (!texture.loadFromFile("Textures/king_w.png"))
			{
				std::cout << "Error loading king texture white" << std::endl;
			}
		}
		else {
			if (!texture.loadFromFile("Textures/king_b.png"))
			{
				std::cout << "Error loading king texture black" << std::endl;
			}
		}
		sprite.setTexture(texture);
	};
	~King() {};
	bool testMove(const bool player, const std::vector<Pieces*>& board, const std::vector<History*>& history, const Position& position, Pieces** garbage);
	bool check(const std::vector<Pieces*>& board, const Position& position);
};
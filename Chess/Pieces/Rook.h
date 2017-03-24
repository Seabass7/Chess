#pragma once

class Rook : public Pieces {
public:
	Rook(bool owner, Position position) : Pieces(Pieces::Rook, owner, position) {
		if (owner == 0) {
			if (!texture.loadFromFile("Textures/rook_w.png"))
			{
				std::cout << "Error loading rook texture white" << std::endl;
			}
		}
		else {
			if (!texture.loadFromFile("Textures/rook_b.png"))
			{
				std::cout << "Error loading rook texture black" << std::endl;
			}
		}
		sprite.setTexture(texture);
	};
	~Rook() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
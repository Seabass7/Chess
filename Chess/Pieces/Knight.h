#pragma once

class Knight : public Pieces {
public:
	Knight(bool owner, Position position) : Pieces(Pieces::Knight, owner, position) {
		if (owner == 0) {
			if (!texture.loadFromFile("Textures/knight_w.png"))
			{
				std::cout << "Error loading knight texture white" << std::endl;
			}
		}
		else {
			if (!texture.loadFromFile("Textures/knight_b.png"))
			{
				std::cout << "Error loading knight texture black" << std::endl;
			}
		}
		sprite.setTexture(texture);
	};
	~Knight() {};
	void draw();
	bool move(const bool player, const std::vector<Pieces*>& board, const Position& position, Pieces** garbage);
};
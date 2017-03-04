#pragma once

class Board {
private:
	std::vector<Pieces*> pieces;
	bool player;
public:
	Board();
	~Board();
	void draw();
	bool move(const Position& position, const Position& destination);
};
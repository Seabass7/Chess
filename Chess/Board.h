#pragma once

class Board {
private:
	std::vector<Pieces*> pieces;
	std::vector<Pieces*> sideBoard; //TODO
	std::vector<History*> history; //TODO
	bool player;
public:
	Board();
	~Board();
	void draw();
	bool move(const Position& position, const Position& destination);
	void remove(Pieces* piece);
};
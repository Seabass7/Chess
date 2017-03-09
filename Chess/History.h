#pragma once

class History {
private:
	Position position, destination;
	Pieces* removedPiece;
public:
	History(Position position, Position destination, Pieces* removedPiece) : position(position), destination(destination), removedPiece(removedPiece) {};
	Position getPosition() { return position; };
	Position getDestination() { return destination; };
	Pieces* getRemovedPiece() { return removedPiece; };
};
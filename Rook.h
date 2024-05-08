#pragma once
#include "Piece.h"
class Rook : public Piece
{
	bool IsFirstMove;
	int move ;
public:
	Rook(int _r, int _c, color _C, Board* _B);
	virtual bool IsLegalMove(Board* B, int sr, int sc, int er, int ec);
	virtual void Draw();
	virtual int getMoves();
	virtual void setMoves();
	virtual char getPieceSym();
	virtual int getTurnNUMbyColor();
};
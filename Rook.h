#pragma once
#include "Piece.h"
class Rook : public Piece
{
	bool IsFirstMove;
	int move ;
	int movecount;
public:
	Rook(int _r, int _c, color _C, Board* _B);
	virtual bool IsLegalMove(Board* B, int sr, int sc, int er, int ec);
	virtual void Draw();
	virtual void Draw(ostream& out)const;
	virtual int getMoves();
	virtual void setMoves();
	virtual char getPieceSym();
	virtual int getTurnNUMbyColor();
	virtual int getROW();
	virtual int getCOL();

	virtual void set_movecount();
	virtual int get_movecount();
};
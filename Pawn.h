#pragma once
#include "Piece.h"

class Pawn : public Piece
{
	
	int move;
	int movecount ;
 public:
	Pawn(int _r,int _c,color _C,Board* _B);
	virtual bool IsLegalMove(Board* B, int sr, int sc, int er, int ec);
	virtual void Draw();
	virtual void Draw(ostream& out)const ;
	//virtual void Possibilities();
	virtual int getMoves();
	virtual void setMoves();
	virtual char getPieceSym();
	virtual int getTurnNUMbyColor();
	virtual int getROW();
	virtual int getCOL();

	virtual void set_movecount();
	virtual int get_movecount();
};


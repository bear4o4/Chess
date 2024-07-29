#pragma once
#include "Header.h"
//#include"Board.h"
#include <math.h>
using namespace std;
class Board;

class Piece
{
protected:
	int ri, ci;
	color C;
	Board* B;
	bool IsHorizontalMove(int sr,int sc,int er,int ec);
	bool IsVerticalMove(int sr, int sc, int er, int ec);
	bool IsDiagonalMove(int sr, int sc, int er, int ec);
	bool IsHorizontalPathClear(Board* B,int sr, int sc, int er, int ec);
	bool IsVertiaclPathClear(Board* B,int sr, int sc, int er, int ec);
	bool IsDiagonalPathClear(Board* B,int sr, int sc, int er, int ec);


public:
	Piece(int _r,int _c, color _C, Board* _B);
	virtual bool IsLegalMove(Board* B,int sr,int sc,int er, int ec)=0;
	virtual void Draw() = 0;
	//virtual void Possibilities() = 0;
	color getColor();
	void moveROWCOL(int i, int j);
	virtual int getMoves()=0;
	virtual void setMoves() = 0;
	virtual char getPieceSym() = 0;
	virtual int getTurnNUMbyColor() = 0;
	virtual int getROW() = 0;
	virtual int getCOL() = 0;
};


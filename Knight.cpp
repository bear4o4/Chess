#include "Knight.h"

Knight::Knight(int _r, int _c, color _C, Board* _B) :Piece(_r, _c, _C, _B)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->B = _B;
	this->move = 0;
}
bool Knight::IsLegalMove(Board* B, int sr, int sc, int er, int ec) {
	int changeinrow, changeincol;
	changeinrow = abs(sr - er);
	changeincol = abs(sc - ec);
	if (changeinrow>0&&changeincol>0) 
	{
		if (changeinrow + changeincol == 3)
		{
			if (changeinrow==2) {
				if (sr-er==-2) {//vertiacl below //first right then left check
					return (IsVerticalMove(sr, sc, sr + 2, sc) && IsHorizontalMove(sr + 2, sc, sr + 2, sc + 1) ) || (IsVerticalMove(sr, sc, sr + 2, sc)  && IsHorizontalMove(sr + 2, sc, sr + 2, sc - 1) );
				}
				else {//vertiacl above
					return (IsVerticalMove(sr, sc, sr - 2, sc)  && IsHorizontalMove(sr - 2, sc, sr - 2, sc + 1) ) || (IsVerticalMove(sr, sc, sr - 2, sc)  && IsHorizontalMove(sr - 2, sc, sr - 2, sc - 1) );

				}
			}
			
			else if (changeinrow == 1) {
				if (sc - ec == -2) {//horizontal right 
					return (IsHorizontalMove(sr, sc, sr, sc + 2)  && IsVerticalMove(sr, sc + 2, sr + 1, sc + 2) ) || (IsHorizontalMove(sr, sc, sr, sc + 2)  && IsVerticalMove(sr, sc + 2, sr - 1, sc + 2));

				}
				else {//horizontal left 
					return (IsHorizontalMove(sr, sc, sr, sc - 2)  && IsVerticalMove(sr, sc - 2, sr + 1, sc - 2) ) || (IsHorizontalMove(sr, sc, sr, sc - 2)  && IsVerticalMove(sr, sc - 2, sr - 1, sc - 2));

				}
			}
			
		}
	}
	return false;
	
}

void Knight::Draw()
{
	cout << ((C == WHITE) ? 'N' : 'n');
}

int Knight::getMoves()
{
	return move;
}

void Knight::setMoves()
{
	move + 1;
}

char Knight::getPieceSym()
{
	if (C == WHITE) {
		return 'N';
	}
	else {
		return 'n';
	}
}

int Knight::getROW()
{
	return ri;
}

int Knight::getCOL()
{
	return ci;
}

int Knight::getTurnNUMbyColor()
{
	if (C == BLACK) {
		return 1;
	}
	else {
		return 0;
	}
}


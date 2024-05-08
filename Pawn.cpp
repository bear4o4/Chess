#include "Pawn.h"

Pawn::Pawn(int _r, int _c, color _C, Board* _B) :Piece(_r,_c,_C,_B)
{
	this->ri = _r;
	this->ci = _c;
	this->C = _C;
	this->B = _B;
	this->move = 0;
}
bool Pawn::IsLegalMove(Board* B, int sr, int sc, int er, int ec) {
	int changeinrow;
	changeinrow = abs(sr - er);

	if (getColor() == BLACK) {
		if ((changeinrow == 2)&&(sc==ec)) {
			return IsVerticalMove(sr, sc, sr - 2, sc) && IsVertiaclPathClear(B, sr, sc, sr - 2, sc);
		}
		else if ((changeinrow == 1) && (sc == ec)) {
			return IsVerticalMove(sr, sc, sr - 1, sc) && IsVertiaclPathClear(B, sr, sc, sr - 1, sc);
		}
	}
	else if (getColor() == WHITE) {//oper
		if ((changeinrow == 2) && (sc == ec)) {
			return IsVerticalMove(sr, sc, sr+2, sc) && IsVertiaclPathClear(B, sr, sc, sr + 2, sc);
		}
		else if ((changeinrow == 1) && (sc == ec)) {
			return IsVerticalMove(sr, sc, sr + 1, sc) && IsVertiaclPathClear(B, sr, sc, sr + 1, sc);
		}
	}
	
	return false;

}

void Pawn::Draw()
{
	cout << ((C == WHITE) ? 'P' : 'p');
}

int Pawn::getMoves()
{
	return move;
}

void Pawn::setMoves()
{
	move + 1;
}

char Pawn::getPieceSym() {
	if (C==WHITE) {
		return 'P';
	}
	else {
		return 'p';
	}
}

int Pawn::getTurnNUMbyColor() {
	if (C==BLACK) {
		return 1;
	}
	else{
		return 0;
	}
}
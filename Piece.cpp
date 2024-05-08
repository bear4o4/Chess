#include "Piece.h"
#include"Board.h"

bool Piece::IsHorizontalMove(int sr, int sc, int er, int ec)
{
	return sr == er;
}

bool Piece::IsVerticalMove(int sr, int sc, int er, int ec)
{
	return sc == ec;
}

bool Piece::IsDiagonalMove(int sr, int sc, int er, int ec)
{
	return abs(er-sr) == abs(ec-sc);
}

bool Piece::IsHorizontalPathClear(Board* B,int sr, int sc, int er, int ec)
{
	if (sc < ec) {
		for (int c = sc+1; c < ec; c++)
		{
			if (B->getPiece(sr,c) != nullptr) {
				return false;
			}
		}
		return true;
	}
	else {
		for (int c = ec + 1; c < sc; c++)
		{
			if (B->getPiece(er, c) != nullptr) {
				return false;
			}
		}
		return true;
	}
}

bool Piece::IsVertiaclPathClear(Board* B,int sr, int sc, int er, int ec)
{
	if (sr < er) {
		for (int r = sr + 1; r < er; r++)
		{
			if (B->getPiece(r,sc) != nullptr) {
				return false;
			}
			
		}
		return true;
	}
	else {
		for (int r = er + 1; r < sr; r++)
		{
			if (B->getPiece(r,ec) != nullptr) {
				return false;
			}
		}	
		return true;
	}
}

bool Piece::IsDiagonalPathClear(Board* B,int sr, int sc, int er, int ec)
{
	int changeinrow, changeincol;
	changeinrow = abs(sr - er);
	changeincol = abs(sc - ec);
	if (changeinrow > 0 && changeincol > 0) 
	{
		if ((sr-er)==(sc-ec)&&sr>er) {
			for (int i = 1; i < changeinrow; i++)
			{
				if (B->getPiece(sr - i, sc - i) != nullptr) {
					return false;
				}
			}
		}
		if ((sr - er) > (sc - ec)) {
			for (int i = 1; i < changeinrow; i++)
			{
				if (B->getPiece(sr - i, sc + i) != nullptr) {
					return false;
				}
			}
		}
		if ((sr - er) == (sc - ec)&&sr<er) {
			for (int i = 1; i < changeinrow; i++)
			{
				if (B->getPiece(sr + i, sc + i) != nullptr) {
					return false;
				}
			}
		}
		if ((sr - er) < (sc - ec)) {
			for (int i = 1; i < changeinrow; i++)
			{
				if (B->getPiece(sr + i, sc - i) != nullptr) {
					return false;
				}
			}
		}
		
		return true;
	}
}

Piece::Piece(int _r, int _c, color _C, Board* _B)
{
	ri = _r;
	ci = _c;
	C = _C;
	B = _B;

}

color Piece::getColor()
{
	return C;
}

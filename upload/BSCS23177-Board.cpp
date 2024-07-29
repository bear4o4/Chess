#pragma once
#include "Board.h"
//#include"Pawn.h"
//#include"Rook.h"
//#include"King.h"
//#include"Queen.h"
//#include"Bishp.h"
//#include"Knight.h"

#include<iostream>
using namespace std;
Board::Board()
{
    Ps = new Piece * *[8];
    for (int ri = 0; ri < 8; ri++)
    {
        Ps[ri] = new Piece * [8];
        for (int ci = 0; ci < 8; ci++)
        {
                if (ri == 0 && ci == 0 || ri == 0 && ci == 7) {
                    Ps[ri][ci] = new Rook(ri, ci, WHITE, this);
                }
                else if (ri == 1) {
                    Ps[ri][ci] = new Pawn(ri, ci, WHITE, this);     //oper wala
                }
                else if (ri == 6) {
                    Ps[ri][ci] = new Pawn(ri, ci, BLACK, this);
                }
                else if (ri == 0 && ci == 1 || ri == 0 && ci == 6) {
                    Ps[ri][ci] = new Knight(ri, ci, WHITE, this);
                }
                else if (ri == 0 && ci == 2 || ri == 0 && ci == 5) {
                    Ps[ri][ci] = new Bishp(ri, ci, WHITE, this);
                }
                else if (ri == 0 && ci == 4) {
                    Ps[ri][ci] = new King(ri, ci, WHITE, this);
                }
                else if (ri == 7 && ci == 4) {
                    Ps[ri][ci] = new King(ri, ci, BLACK, this);
                }
                else  if (ri == 0 && ci == 3) {
                    Ps[ri][ci] = new Queen(ri, ci, WHITE, this);
                }
                else if (ri == 7 && ci == 3) {
                    Ps[ri][ci] = new Queen(ri, ci, BLACK, this);
                }
                else if (ri == 7 && ci == 0 || ri == 7 && ci == 7) {
                    Ps[ri][ci] = new Rook(ri, ci, BLACK, this);
                }
                else if (ri == 7 && ci == 1 || ri == 7 && ci == 6) {
                    Ps[ri][ci] = new Knight(ri, ci, BLACK, this);
                }
                else  if (ri == 7 && ci == 2 || ri == 7 && ci == 5) {
                    Ps[ri][ci] = new Bishp(ri, ci, BLACK, this);
                }
                else {
                    Ps[ri][ci] = nullptr;
                }
        }
    }
}

void Board::PRINTboard()
{
    system("cls");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Ps[i][j]==nullptr) {
                cout << "-";
            }
            else {
                Ps[i][j]->Draw();
            }
        }
        cout << endl;

    }
}

Piece* Board::getPiece(int r,int c)
{
    return Ps[r][c];
}

Piece* Board::setPiece(int sr, int sc,  int er, int ec)
{
    Piece*** temp ;
    temp = new Piece * *[8];
    for (int ri = 0; ri < 8; ri++)
    {
        temp[ri] = new Piece * [8];
        for (int ci = 0; ci < 8; ci++)
        {
            temp[ri][ci] = nullptr;
        }
    }

    temp[sr][sc] = Ps[sr][sc];
    Ps[sr][sc] = nullptr;
    return  Ps[er][ec] = temp[sr][sc];
    
}

void Board::swapPiece(int i, int j, Piece* temp)
{
    /* // Piece* T = Ps[i][j];
    Ps[i][j] = nullptr;
    Ps[temp->getROW()][temp->getCOL()] = T;
    return T;*/
    

    if(temp!=nullptr) {
        Ps[i][j] = temp;
        Ps[i][j]->moveROWCOL(i, j);
    }
    else { Ps[i][j] = temp; }
}










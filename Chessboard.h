#pragma once
#include "Figure.h"
#include <vector>

using namespace std;

class Chessboard
{
public:
	Chessboard() {}
	~Chessboard() {}
	void ReadFigure2Chessboard(istream& in);
	bool RemoveFigureFromChessboard(const Figure& fig);
	void Print(ostream& out) const;
	void Read(istream& in);
	Figure& GetElementByIndex(int index);
	Figure& operator[] (int index);
	Figure operator[] (int index)const;
	Chessboard& operator+= (const Figure& fig);
	Chessboard& operator-= (const Figure& fig);
	void CheckMatePat();
	void ChangeChessboard();
	bool IsPosOccupied(const Figure& fig);
private:
	vector<Figure> chessboard;
	string CheckMatePat(const Figure& wKing);
	bool AddFigure2Chessboard(const Figure& fig);
};

istream& operator>> (istream& in, Chessboard& cb);
ostream& operator<< (ostream& out, const Chessboard& cb);
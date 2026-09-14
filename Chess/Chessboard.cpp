#include "Chessboard.h"
#include <algorithm>
#include <stdexcept>

bool Chessboard::AddFigure2Chessboard(const Figure & fig)
{
	if (IsPosOccupied(fig))
		return false;
	chessboard.push_back(fig);
	return true;
}

void Chessboard::ReadFigure2Chessboard(istream& in)
{
	Figure temp;
	in >> temp;
	*this += temp;
}

bool Chessboard::RemoveFigureFromChessboard(const Figure & fig)
{
	int len = chessboard.size();
	if (chessboard.begin() == chessboard.end()) {
		return false;
	}
	chessboard.erase(remove(chessboard.begin(), chessboard.end(), fig), chessboard.end());
	return len > chessboard.size();
} 

void Chessboard::Print(ostream& out) const
{
	out << endl;
	for (int i = 0; i < chessboard.size(); ++i) {
		out << i + 1 << ": ";
		out << chessboard[i];
	}
	if (!chessboard.size()) {
		out << "Chessboard is emrty." << endl;
	}
	out << "#####" << endl;
	out << endl;
}

void Chessboard::Read(istream & in)
{
	int count = 0;
	in >> count;
	for (int i = 0; i < count; ++i) {
		ReadFigure2Chessboard(in);
	}
}

Figure & Chessboard::GetElementByIndex(int index)
{
		return chessboard.at(index);
}

Figure & Chessboard::operator[](int index)
{
	return GetElementByIndex(index);
}

Figure Chessboard::operator[](int index) const
{
	return chessboard.at(index);
}

Chessboard & Chessboard::operator+=(const Figure & fig)
{
	AddFigure2Chessboard(fig);
	return *this;
}

Chessboard & Chessboard::operator-=(const Figure & fig)
{
	RemoveFigureFromChessboard(fig);
	return *this;
}

string Chessboard::CheckMatePat(const Figure & wKing)
{
	vector <boolPosition> DangerousPoints;
	Position temp;
	boolPosition booltemp;
	int start1 = wKing.GetRole()->GetPosition()._1 - 1, end1 = wKing.GetRole()->GetPosition()._1 + 2;
	for (start1; start1 < end1; ++start1) {
		int start2 = wKing.GetRole()->GetPosition()._A - 1, end2 = wKing.GetRole()->GetPosition()._A + 2;
		for (start2; start2 < end2; ++start2) {
			if ((start2 >= 'A') && (start2 <= 'H')) {
				temp._A = (char)start2;
			}
			else {
				continue;
			}
			if (start1 <= 8 && start1 >= 1) {
				temp._1 = start1;
			}
			else { 
				continue; 
			}
			if (wKing != temp) {
				booltemp.pose = temp;
				booltemp.inDanger = false;
				DangerousPoints.push_back(booltemp);
			}
		}
	}
	bool check = false;
	for (int i = 0; i < chessboard.size(); ++i) {
		if (chessboard[i] != wKing) {
			chessboard[i].ChangeRole(RoleFactory::SetVictim(chessboard[i].GetRole(), wKing.GetPosition()));
			if (chessboard[i].GetRole()->IsDangerous()) {
				check = true;
			}
			else {
				for (int j = 0; j < DangerousPoints.size(); ++j) {
					chessboard[i].ChangeRole(RoleFactory::SetVictim(chessboard[i].GetRole(), DangerousPoints[j].pose));
					if (chessboard[i].GetRole()->IsDangerous()) {
						DangerousPoints[j].inDanger = true;
					}
				}
			}
		}
	}
	int checks = 0;
	for (int i = 0; i < DangerousPoints.size(); ++i) {
		if (DangerousPoints[i].inDanger)
			++checks;
	}
	if (checks == DangerousPoints.size()) {
		if (check)
			return "Mate";
		return "Pat";
	}
	else {
		if (check) {
			return "Check";
		}
		else {
			return "Common situation";
		}
	}
}

void Chessboard::CheckMatePat()
{
	cout << "____________________" << endl;
	cout << endl;
	for (int i = 0; i < chessboard.size(); ++i) {
		if (chessboard[i].GetRole()->WhatRole() == "King" && chessboard[i].GetColor() == "White") {
			cout << "White King (" << i + 1 << "). \nSituation: " << CheckMatePat(chessboard[i]) << endl;
		}
	}
	cout << "____________________" << endl;
}

void Chessboard::ChangeChessboard()
{
	cout << "Enter 1 to clear Your_Chessboard" << endl;
	cout << "Enter 2 to change figures" << endl;
	cout << "Enter 3 to add new figure" << endl;
	cout << "Enter 4 to delete figure" << endl;
	cout << "Enter 0 to exit" << endl;
	cout << endl;
	int commandLev2;
	cin >> commandLev2;
	switch (commandLev2) {
	case 0: return;
	case 1: 
		while (chessboard.size()) {
			*this -= chessboard[0];
		}
		return;
	case 2: 
		cout << "Enter the index of figure in Your_Chessboard" << endl;
		cout << endl;
		int num;
		cin >> num;
		if (IsPosOccupied(chessboard[num - 1].ChangeFigure())) {
			cout << "Position occupied, enter another position" << endl;
		}
		return;
	case 3: 
		cout << "Enter the data of new figure: 'King' 'White' 'A' '1'" << endl;
		cout << endl;

		ReadFigure2Chessboard(cin);
		return;
	case 4: 
		cout << "Enter the index of figure to delete" << endl;
		cout << endl;
		int indx;
		cin >> indx;
		*this -= chessboard[indx - 1];
		return;
	}
}

bool Chessboard::IsPosOccupied(const Figure & fig)
{
	for (const auto x : chessboard) {
		if (x.GetPosition() == fig.GetPosition())
			return true;
	}
	return false;
}

istream & operator>>(istream & in, Chessboard & cb)
{
	cb.Read(in);
	return in;
}

ostream & operator<<(ostream & out, const Chessboard & cb)
{
	cb.Print(out);
	return out;
}

#pragma once
#include <iostream>
#include <string>
#include "Role.h"
#include "RoleFactory.h"
#include "Position.h"

using namespace std;

class Figure {
public:
	Figure() : role(nullptr) {}
	Figure(const Figure& fig);
	~Figure();

	void Print(ostream& out)const;
	void Read(istream& in);

	void SetPosition(Position _Pos);
	void ReadPosition(istream& in);
	Position GetPosition()const;

	void ChangeCol(istream& in);
	void ChangeRow(istream& in);

	void ChangeRole(const Role * role);
	void ReadRole(istream & in);
	Role * GetRole()const;
	void SetColor(const string color);
	void ReadColor(istream & in);
	string GetColor()const;
	bool IsEqualFig(const Figure& right) const;
	bool IsEqualPosition(const Figure& right) const;
	bool operator == (const Figure& right) const;
	bool operator == (const Position& _pos) const;
	bool operator != (const Figure& right) const;
	bool operator != (const Position& _pos) const;
	Figure& operator= (const Figure& right);
	Figure& operator++ ();
	Figure& operator-- (); 
	Figure ChangeFigure();
private:
	string color;
	Role * role;
};

istream& operator>> (istream& in, Figure& fig);
ostream& operator<< (ostream& out, const Figure& fig);
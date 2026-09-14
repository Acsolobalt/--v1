#include "Figure.h"
#include <string>
#include <iostream>
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Castle.h"
#include "Pawn.h" 

using namespace std;

Figure::Figure(const Figure & fig) : color(fig.color)
{
	role = RoleFactory::CopyRole(fig.GetRole());
}

Figure::~Figure()
{
	if (role)
		delete role;
}

void Figure::Print(ostream& out) const
{
	if (role) {
		out << role->WhatRole() << " " << color << " ";
		role->GetPosition().printPosition(out);
	}
	out << endl;
}

void Figure::Read(istream & in)
{
	string temp;
	in >> temp >> color;
	Position Pose;
	Pose.readPosition(in);
	role = RoleFactory::CreateRole(RoleFactory::ConvertRole(temp), Pose);
}

void Figure::SetPosition(Position Ps)
{
	string temp = role->WhatRole();
	if (role)
		delete role;
	role = RoleFactory::CreateRole(RoleFactory::ConvertRole(temp), Ps);
}

void Figure::ReadPosition(istream & in)
{
	Position p;
	p.readPosition(cin);
	SetPosition(p);
}

Position Figure::GetPosition() const
{
	if(role) 
		return role->GetPosition();
}

void Figure::ChangeCol(istream& in)
{
	Position temp;
	temp.readColumn(in);
	SetPosition(temp);
}

void Figure::ChangeRow(istream& in)
{
	Position temp;
	temp.readRow(in);
	SetPosition(temp);
}

void Figure::ChangeRole(const Role * rl)
{
	if (role)
		delete role;
	role = (Role *)rl;
}

void Figure::ReadRole(istream & in)
{
	string temp;
	cin >> temp;
	Position tempPos = role->GetPosition();
	ChangeRole(RoleFactory::CreateRole(RoleFactory::ConvertRole(temp), tempPos));
}

Role * Figure::GetRole() const
{
	return role;
}

void Figure::SetColor(const std::string cl)
{
	if (cl == "White" || cl == "Black")
		color = cl;
}

void Figure::ReadColor(istream & in)
{
	string temp;
	cin >> temp;
	SetColor(temp);
}

std::string Figure::GetColor() const
{
	return color;
}	

bool Figure::IsEqualFig(const Figure& right) const
{
	return (color == right.color && role->WhatRole() == right.role->WhatRole());
}

bool Figure::IsEqualPosition(const Figure& right) const
{
	return (role->GetPosition() == right.role->GetPosition());
}

bool Figure::operator==(const Figure & right) const
{
	return (role->WhatRole() == right.role->WhatRole() && color == right.color && role->GetPosition() == right.role->GetPosition());
}

bool Figure::operator==(const Position & _pos) const
{
	return (role->GetPosition() == _pos);
}

bool Figure::operator!=(const Figure & right) const
{
	return !(*this == right);
}

bool Figure::operator!=(const Position & _pos) const
{
	return !(role->GetPosition() == _pos);
}

Figure & Figure::operator=(const Figure & right)
{
	if (this != &right) {
		if (role)
			delete role;
		role = RoleFactory::CopyRole(right.role);
		this->color = right.color;
	}
	return *this;
}

Figure & Figure::operator++() 
{
	if (role->GetPosition()._1 < 8) {
		int _1 = role->GetPosition()._1;
		Position Pose = { role->GetPosition()._A, ++_1 };
		string clr = color, rl = role->WhatRole();
		delete role;
		role = RoleFactory::CreateRole(RoleFactory::ConvertRole(rl), Pose);
	}
	return *this;
}

Figure & Figure::operator--() 
{
	if (role->GetPosition()._1 > 1) {
		int _1 = role->GetPosition()._1;
		Position Pose = { role->GetPosition()._A, --_1 };
		string clr = color, rl = role->WhatRole();
		delete role;
		role = RoleFactory::CreateRole(RoleFactory::ConvertRole(rl), Pose);
	}
	return *this;
}

Figure Figure::ChangeFigure()
{
	cout << "Enter 1 to change Role" << endl;
	cout << "Enter 2 to change Color" << endl;
	cout << "Enter 3 to change Position" << endl;
	cout << "Enter 0 to exit" << endl;
	cout << endl;
	Figure changed = *this;	
	int commandLev3, commandLev4, commandLev5;
	cin >> commandLev3;
	switch (commandLev3) {
	case 0: return *this;
	case 1: 
		cout << "Enter the Role" << endl;
		cout << endl;
		ReadRole(cin);
		return *this;
	case 2:
		cout << "Enter the Color" << endl;
		cout << endl;
		ReadColor(cin);
		return *this;
	case 3:
		cout << "Enter 1 to change Column" << endl;
		cout << "Enter 2 to change Row" << endl;
		cout << "Enter 3 to enter Position" << endl;
		cout << "Enter 0 to exit" << endl;
		cout << endl;
		cin >> commandLev4;
		switch (commandLev4) {
		case 0: ChangeFigure(); break;
		case 1: 
			cout << "Enter the Column" << endl;
			cout << endl;
			changed.ChangeCol(cin); break;
		case 2:
			cout << "Enter 1 to move the figure 1 square up" << endl;
			cout << "Enter 2 to move the figure 1 square down" << endl;
			cout << "Enter 3 to enter the Row" << endl;
			cout << "Enter 0 to exit" << endl;
			cout << endl;
			cin >> commandLev5;
			switch (commandLev5) {
			case 0: ChangeFigure(); break;
			case 1:
				++changed; break;
			case 2: 
				--changed; break;
			case 3: 
				changed.ChangeRow(cin); break;
			} break;
		case 3: 
			cout << "Enter the Position: 'A' '1'" << endl;
			cout << endl;
			changed.ReadPosition(cin);
		}
		return changed;
	}
}

istream & operator>>(istream & in, Figure & fig)
{
	fig.Read(in);
	return in;
}

ostream & operator<<(ostream & out, const Figure & fig)
{
	fig.Print(out);
	return out;
}

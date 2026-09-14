#include "RoleFactory.h"

Role * RoleFactory::CopyRole(Role * r)
{
	if (dynamic_cast<King*>(r))
		return new King(r);
	if (dynamic_cast<Queen*>(r))
		return new Queen(r);
	if (dynamic_cast<Bishop*>(r))
		return new Bishop(r);
	if (dynamic_cast<Knight*>(r))
		return new Knight(r);
	if (dynamic_cast<Castle*>(r))
		return new Castle(r);
	if (dynamic_cast<Pawn*>(r))
		return new Pawn(r);
}

Role * RoleFactory::CreateRole(ROLE role, Position p)
{
	switch (role) {
	case KING:
		return new King(p);
	case QUEEN:
		return new Queen(p);
	case BISHOP:
		return new Bishop(p);
	case KNIGHT:
		return new Knight(p);
	case CASTLE:
		return new Castle(p);
	case PAWN:
		return new Pawn(p);
	default:
		cout << "Wrong role" << endl;
		return nullptr;
	}
}

Role * RoleFactory::SetVictim(Role* r, Position v)
{
	string role = r->WhatRole();
	ROLE temp = ConvertRole(role);
	switch (temp) {
	case KING:
		return new King(r->GetPosition(), v);
	case QUEEN:
		return new Queen(r->GetPosition(), v);
	case BISHOP:
		return new Bishop(r->GetPosition(), v);
	case KNIGHT:
		return new Knight(r->GetPosition(), v);
	case CASTLE:
		return new Castle(r->GetPosition(), v);
	case PAWN:
		return new Pawn(r->GetPosition(), v);
	default:
		return nullptr;
	}
}

ROLE RoleFactory::ConvertRole(string r) {
	if (r == "King")
		return ((ROLE)0);
	else if (r == "Queen")
		return ((ROLE)1);
	else if (r == "Bishop")
		return ((ROLE)2);
	else if (r == "Knight")
		return ((ROLE)3);
	else if (r == "Castle")
		return ((ROLE)4);
	else if (r == "Pawn")
		return ((ROLE)5);
}
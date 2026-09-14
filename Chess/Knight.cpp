#include "Knight.h"
#include <iostream>

Knight::Knight(Role * p) : myPos(Position{ 'A', 1 }), DangerousFor(Position{ 'A', 1 })
{
	Knight* k = (Knight*)p;
	if (p) {
		myPos = k->myPos;
		DangerousFor = k->DangerousFor;
	}
}

bool Knight::IsDangerous() const
{
	return ((abs(DangerousFor._A - myPos._A) == 2) && (abs(DangerousFor._1 - myPos._1) == 1) ||
		(abs(DangerousFor._1 - myPos._1) == 2) && (abs(DangerousFor._A - myPos._A) == 1));
}

Position Knight::GetPosition() const
{
	return myPos;
}

string Knight::WhatRole() const
{
	return "Knight";
}
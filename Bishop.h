#include "Bishop.h"
#include <iostream>

Bishop::Bishop(Role * p) : myPos(Position{ 'A', 1 }), DangerousFor(Position{ 'A', 1 })
{
	Bishop* k = (Bishop*)p;
	if (p) {
		myPos = k->myPos;
		DangerousFor = k->DangerousFor;
	}
}

bool Bishop::IsDangerous() const
{
	return abs(DangerousFor._A - myPos._A) == abs(DangerousFor._1 - myPos._1);
}

Position Bishop::GetPosition() const
{
	return myPos;
}

string Bishop::WhatRole() const
{
	return "Bishop";
}

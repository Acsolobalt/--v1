#include "Queen.h"
#include <iostream>

Queen::Queen(Role * p) : myPos(Position{ 'A', 1 }), DangerousFor(Position{ 'A', 1 })
{
	Queen* k = (Queen*)p;
	if (p) {
		myPos = k->myPos;
		DangerousFor = k->DangerousFor;
	}
}

bool Queen::IsDangerous() const
{
	return (DangerousFor._A == myPos._A || DangerousFor._1 == myPos._1) ||
		(abs(DangerousFor._A - myPos._A) == abs(DangerousFor._1 - myPos._1));
}

Position Queen::GetPosition() const
{
	return myPos;
}

string Queen::WhatRole() const
{
	return "Queen";
}
#include "Castle.h"
#include <iostream>

Castle::Castle(Role * p) : myPos(Position{ 'A', 1 }), DangerousFor(Position{ 'A', 1 })
{
	Castle* k = (Castle*)p;
	if (p) {
		myPos = k->myPos;
		DangerousFor = k->DangerousFor;
	}
}

bool Castle::IsDangerous() const
{
	return DangerousFor._A == myPos._A || DangerousFor._1 == myPos._1;
}

Position Castle::GetPosition() const
{
	return myPos;
}

string Castle::WhatRole() const
{
	return "Castle";
}
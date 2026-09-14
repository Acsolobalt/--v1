#include "King.h"
#include <iostream>

King::King(Role * p) : myPos(Position { 'A', 1 }), DangerousFor(Position { 'A', 1 })
{
	King* k = (King*)p;
	if (p) {
		myPos = k->myPos;
		DangerousFor = k->DangerousFor;
	}	
}

bool King::IsDangerous() const
{
	return (abs(DangerousFor._A - myPos._A) <= 1 && abs(DangerousFor._1 - myPos._1) <= 1);
}

Position King::GetPosition() const
{
	return myPos;
}

string King::WhatRole() const
{
	return "King";
}

King::King(Position mP, Position _victim) : myPos(mP), DangerousFor(_victim)
{
}

King::King(Position mP) : myPos(mP)
{
}

#include "Pawn.h"
#include <iostream>

Pawn::Pawn(Role * p) : myPos(Position{ 'A', 1 }), DangerousFor(Position{ 'A', 1 })
{
	Pawn* k = (Pawn*)p;
	if (p) {
		myPos = k->myPos;
		DangerousFor = k->DangerousFor;
	}
}

bool Pawn::IsDangerous() const
{
	return (abs(DangerousFor._A - myPos._A) == 1) && (DangerousFor._1 - myPos._1 == 1);
}

Position Pawn::GetPosition() const
{
	return myPos;
}

string Pawn::WhatRole() const
{
	return "Pawn";
}
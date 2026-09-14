#pragma once
#include "Role.h"
#include <string>
using namespace std;

class Pawn : public Role
{
public:
	Pawn(Position mPs) : myPos(mPs) {}
	Pawn(Position mPs, Position vict) : myPos(mPs), DangerousFor(vict) {}
	Pawn(Role* p);
	virtual ~Pawn() {}
	virtual bool IsDangerous()const override;
	virtual Position GetPosition()const override;
	virtual string WhatRole()const override;
private:
	Position myPos, DangerousFor;
};
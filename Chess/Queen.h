#pragma once
#include "Role.h"
#include <string>
using namespace std;

class Queen : public Role
{
public:
	Queen(Position mPs) : myPos(mPs) {}
	Queen(Position mPs, Position vict) : myPos(mPs), DangerousFor(vict) {}
	Queen(Role* p);
	virtual ~Queen() {}
	virtual bool IsDangerous()const override;
	virtual Position GetPosition()const override;
	virtual string WhatRole()const override;
private:
	Position myPos, DangerousFor;
};
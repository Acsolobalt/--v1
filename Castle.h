#pragma once
#include "Role.h"
#include <string>
using namespace std;

class Castle : public Role
{
public:
	Castle(Position mPs) : myPos(mPs) {}
	Castle(Position mPs, Position vict) : myPos(mPs), DangerousFor(vict) {}
	Castle(Role* p);
	virtual ~Castle() {}
	virtual bool IsDangerous()const override;
	virtual Position GetPosition()const override;
	virtual string WhatRole()const override;
private:
	Position myPos, DangerousFor;
};
#pragma once
#include "Role.h"
#include <string>
using namespace std;

class Bishop : public Role
{
public:
	Bishop(Position mPs) : myPos(mPs) {}
	Bishop(Position mPs, Position vict) : myPos(mPs), DangerousFor(vict) {}
	Bishop(Role* p);
	virtual ~Bishop() {}
	virtual bool IsDangerous()const override;
	virtual Position GetPosition()const override;
	virtual string WhatRole()const override;
private:
	Position myPos, DangerousFor;
};
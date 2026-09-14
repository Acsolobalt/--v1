#pragma once
#include "Role.h"
#include <string>
using namespace std;

class Knight : public Role
{
public:
	Knight(Position mPs) : myPos(mPs) {}
	Knight(Position mPs, Position vict) : myPos(mPs), DangerousFor(vict) {}
	Knight(Role* p);
	virtual ~Knight() {}
	virtual bool IsDangerous()const override;
	virtual Position GetPosition()const override;
	virtual string WhatRole()const override;
private:
	Position myPos, DangerousFor;
};
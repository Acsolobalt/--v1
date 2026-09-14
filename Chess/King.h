#pragma once
#include "Role.h"
#include <string>
using namespace std;

class King : public Role
{
public:
	King(Position mPs );
	King(Position mPs, Position vict);
	King(Role* p);
	virtual ~King() {}
	virtual bool IsDangerous()const override;
	virtual Position GetPosition()const override;
	virtual string WhatRole()const override;
private:
	Position myPos, DangerousFor;
};
#pragma once
#include <string>
#include <vector>
#include "Position.h"
using namespace std;

class Role
{
public:
	virtual bool IsDangerous()const = 0;
	virtual Position GetPosition()const = 0;
	virtual string WhatRole()const = 0;
	virtual ~Role() {}
};
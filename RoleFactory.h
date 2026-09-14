#pragma once

#include "Role.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Castle.h"
#include "Pawn.h" 

enum ROLE { KING, QUEEN, BISHOP, KNIGHT, CASTLE, PAWN };

class RoleFactory
{
public:
	static Role* CopyRole(Role* r);
	static Role* CreateRole(ROLE role, Position _p);
	static Role* SetVictim(Role* r, Position _v);
	static ROLE ConvertRole(string r);
};
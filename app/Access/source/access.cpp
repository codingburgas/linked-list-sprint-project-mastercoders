#include "pch.h"
#include "access.h"
#include "global.h"

namespace Access
{
	bool Init()
	{
		if (!Global::Init())
			return false;
		return true;
	}
	bool Release()
	{
		return true;
	}
}
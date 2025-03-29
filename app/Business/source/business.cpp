#include "pch.h"
#include "business.h"
#include "global.h"
namespace Business
{
	bool Init()
	{
		if (!Global::Init())
			return false;
		return true;
	}
	bool Release()
	{
		if (!Global::Release())
			return false;
		return true;
	}
}
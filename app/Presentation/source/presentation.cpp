#include "pch.h"
#include "presentation.h"
#include "access.h"
namespace Presentation
{
	bool Init()
	{
		if (!Access::Init())
			return false;
		return true;
	}
	bool Release()
	{
		if (!Access::Release())
			return false;
		return true;
	}
}
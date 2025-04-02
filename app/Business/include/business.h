#pragma once

namespace Business
{
	// init global vars, execute startup functions
	bool Init();
	// release global vars, execute cleanup functions
	bool Release();
}
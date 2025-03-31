#pragma once

namespace Process
{
	// user log in processing
	int LogIn(const User& data);
	// user sign up processing
	int SignUp(const User& data);
	// get register input
	int InputLogSign(const int& mode);
}
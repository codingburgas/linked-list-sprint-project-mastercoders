#include <iostream>
#include <vector>
#include "list.h"
#include "user.h"
#include "create.h"
#include "register.h"
#include "global.h"
#include <fstream>
#pragma warning(disable : 4996)
int main()
{
	std::cout << Register::RegisterUser({ "Daniel123456567","Pass123456789" });
}
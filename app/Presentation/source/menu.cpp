#include "pch.h"
#include "menu.h"
#include "caption.h"
#include "process.h"
#include "presentation.h"
namespace Menu
{
	void Main()
	{
		if (!Presentation::Init()) // init other logic layers
		{
			std::cout << "\nInternal error. Quiting!";
			Sleep(500);
			exit(1);
		}

		InitialMenu(); //call initial menu
		MainMenu(); // call main program menu

		if (!Presentation::Release()) // release other logic layers
		{
			std::cout << "\nInternal error. Quiting!";
			Sleep(500);
			exit(1);
		}
	}
	void InitialMenu()
	{
		Caption::PrintCaption(); // print art text caption

		initial: // inital options ticket

		std::cout << std::endl;
		std::cout << "Options:\n";
		std::cout << "1. Log In\n";
		std::cout << "2. Sign Up\n";
	
		std::string choice = ""; //get user's choice
		do
		{
			std::cout << ":";		
			std::cin >> choice; //get user's choice

		} while ((choice != "1" && choice != "2"));

		Utils::Clear();

		switch (Process::InputLogSign(atoi(choice.c_str()))) //switch inital options error code
		{
		case Error::SUCCESSFUL: Utils::Clear(); break;
		default:
		{
			Utils::Clear();
			std::cout << "\nError\n";
			Sleep(500); // wait 0.5 seconds to show error msg
			Utils::Clear();
			
			goto initial;
			break;
		}
		};
	}
	void MainMenu()
	{
		
	}

}
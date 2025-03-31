#include "pch.h"
#include "menu.h"
#include "caption.h"
#include "process.h"
#include "presentation.h"
#include "options.h"
namespace Menu
{
	void Main()
	{
		if (!Presentation::Init()) // init other logic layers
		{
			std::cerr << "\nInternal error. Quiting!";
			Sleep(500);
			exit(1);
		}

		InitialMenu(); //call initial menu
		MainMenu(); // call main program menu

		if (!Presentation::Release()) // release other logic layers
		{
			std::cerr << "\nInternal error. Quiting!";
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

		switch (Process::InputLogSign(std::stoi(choice))) //switch inital options error code
		{
		case Error::SUCCESSFUL: Utils::Clear(); break;
		default:
		{
			Utils::Clear();
			std::cerr << "\nError\n";
			Sleep(500); // wait 0.5 seconds to show error msg
			Utils::Clear();
			
			goto initial;
			break;
		}
		};
	}
	void MainMenu()
	{
		std::string choice = ""; // user choice;
		while (choice != "0")
		{
			std::cout << "Options:\n";
			std::cout << "0. exit\n";
			std::cout << "1. show all events\n";
			std::cout << "2. insert a new event\n";
			std::cout << "3. replace an existing event\n";
			std::cout << "4. delete an existing event\n";

			std::cout << ":";
			std::cin >> choice;

			Utils::Clear();
			switch (std::stoi(choice))
			{
			case 0:
			{
				std::cout << "\nQuiting!";
				Sleep(500);
				exit(0);
				break;
			}
			case 1: Options::ShowAllEvents(); break;
			case 2: Options::InsertEvent(); break;
			}
		}
	}

}
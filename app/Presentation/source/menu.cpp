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
			Utils::Exit(); // exit if init fails
		}

		InitialMenu(); //call initial menu
		MainMenu(); // call main program menu

		if (!Presentation::Release()) // release other logic layers
		{
		}
		Utils::Exit();
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
			Utils::ErrMsg("Error");

			goto initial;
			break;
		}
		};
	}
	void MainMenu()
	{
		std::string choice = ""; // user choice;
		while (true)
		{
			std::cout << "Options:\n";
			std::cout << "\n1. exit\n";
			std::cout << "\n2. show all events\n";
			std::cout << "\n3. insert a new event\n";
			std::cout << "\n4. replace an existing event\n";
			std::cout << "\n5. delete an existing event\n";
			std::cout << "\n6. show all event names\n";
			std::cout << "\n7. show events by topic\n";
			std::cout << "\n8. search for an event\n";

			std::cout << "\nEnter choice:\n";
			Utils::EnterNumber(choice);

			Utils::Clear();
			switch (std::stoi(choice))
			{
			case 1: Options::Exit(); return; break;
			case 2: Options::ShowAllEvents(); break;
			case 3: Options::InsertEvent(); break;
			case 4: Options::ReplaceEvent(); break;
			case 5: Options::DeleteEvent(); break;
			case 6: Options::ShowNames(); break;
			case 7:	Options::ShowTopicEvents(); break;
			case 8: Options::SearchEvent(); break;
			}
			Utils::Clear();
		}
	}

}
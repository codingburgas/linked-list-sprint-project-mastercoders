// Builder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "list.h"
int main()
{
	ListEvent le;
	EventData data[3];
	data[0].name = "event1";
	data[1].name = "event2";
	data[2].name = "event3";

	data[0].otherData = data[1].otherData = data[2].otherData = {};
	
	data[0].topic = "topic1";
	data[1].topic = "topic2";
	data[2].topic = "topic3";

	data[0].year = 1901;
	data[1].year = 1902;
	data[2].year = 1903;

	for(int i = 0; i < 3;i++)
	le.InsertDate(data[i]);

	le.PrintEvent();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

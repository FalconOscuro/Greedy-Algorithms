#include "Programs.h"

void main()
{
	int choice;
	bool running = true;

	while (running)
	{
		cout << "Please pick a program to run (1 - The vending machine)   ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
			running = VendingMachine();

		else
			cout << "Invalid input, please try again" << endl;
	}

	cout << "Ending Program";
}
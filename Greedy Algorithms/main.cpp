#include "Programs.h"

void main()
{
	int choice;
	bool running = true;
	srand(time(NULL));

	while (running)
	{
		cout << "Please pick a program to run (1 - The vending machine, 2 - Delivery driver)   ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
			running = VendingMachine();

		else if (choice == 2)
			running = DeliveryDriver();

		else
			cout << "Invalid input, please try again" << endl;
	}

	cout << "Ending Program";
}
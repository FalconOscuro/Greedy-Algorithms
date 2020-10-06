#include "Programs.h"

void main()
{
	int choice;
	bool running = true;
	srand(time(NULL));

	while (running)
	{
		cout << "Please pick a program to run (1 - The vending machine, 2 - Delivery driver, 3 - Inventory Manager)   ";
		cin >> choice;
		cout << endl;

		if (choice == 1)
			running = VendingMachine();

		else if (choice == 2)
			running = DeliveryDriver();

		else if (choice == 3)
			running = InventoryManager();

		else
			cout << "Invalid input, please try again" << endl;
	}

	cout << "Ending Program";
}
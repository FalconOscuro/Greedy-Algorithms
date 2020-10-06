#include "Programs.h"

bool InventoryManager()
{
	vector<Item> itemTable;
	for (int i = 0; i < 10; i++)
		itemTable.push_back(Item());

	while (true)
	{
		cout << "Generating Item table..." << endl;
		cout << "Item table (ItemID, Value, Weight, Heuristic)" << endl;
		for (int i = 0; i < itemTable.size(); i++)
		{
			itemTable[i].ReGenerateItem();
			cout << i << "   " << itemTable[i].value << "   " << itemTable[i].weight << "   " << itemTable[i].heuristic << endl;
		}

		cout << "Total inventory value " << FindNextItem(&itemTable, 100, 0);

		cout << "Do you want to quit the program (q), run a different algorithm (d), or run again (a)?   ";
		char choice;
		cin >> choice;
		cout << endl;

		if (choice == 'q' || choice == 'Q')
			return false;

		else if (choice == 'd' || choice == 'D')
			return true;
	}
}

int FindNextItem(vector<Item>* itemTable, int carryWeight, int invWeight)
{
	int bestItemID = -1;

	for (int i = 0; i < itemTable->size(); i++)
	{
		if (itemTable->operator[](i).canBeHeld == false)
			continue;

		else if (itemTable->operator[](i).weight + invWeight > carryWeight)
			itemTable->operator[](i).canBeHeld = false;

		else
		{
			if (bestItemID == -1)
				bestItemID = i;

			else if (itemTable->operator[](bestItemID).heuristic < itemTable->operator[](i).heuristic)
				bestItemID = i;
		}
	}

	if (bestItemID == -1)
	{
		cout << "Inventory full or no more items to pick up" << endl;
		return 0;
	}

	cout << "Picking up item ID " << bestItemID << " weighing " << itemTable->operator[](bestItemID).weight << " worth " << itemTable->operator[](bestItemID).value << endl;

	itemTable->operator[](bestItemID).canBeHeld = false;

	return itemTable->operator[](bestItemID).value + FindNextItem(itemTable, carryWeight, invWeight);
}

void Item::ReGenerateItem()
{
	value = rand() % 500 + 1;
	weight = rand() % 50 + 1;
	canBeHeld = true;
	heuristic = value / weight;
}
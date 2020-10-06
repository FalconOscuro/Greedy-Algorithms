#include "Programs.h"

bool VendingMachine()
{
	while (true)
	{
		double changeIn = 0;

		cout << "Input an amount of change (0.00)   ";
		cin >> changeIn;
		cout << endl;

		changeIn = Round(changeIn);
		
		FindNextChange(changeIn);
		cout << endl;

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

// A recursive algorithm that finds the next largest amount of change
void FindNextChange(double changeLeft)
{
	// String that stores the coin used on this iteration and prints it
	string out = "NULL";

	// Checks to see, from the largest coin possible, if that coin can be used
	if (changeLeft - 1 >= 0)
	{
		changeLeft -= 1;
		out = "1";
	}

	else if (changeLeft - 0.5 >= 0)
	{
		changeLeft -= 0.5;
		out = "0.5";
	}

	else if (changeLeft - 0.2 >= 0)
	{
		changeLeft -= 0.2;
		out = "0.2";
	}

	else if (changeLeft - 0.1 >= 0)
	{
		changeLeft -= 0.1;
		out = "0.1";
	}

	else if (changeLeft - 0.05 >= 0)
	{
		changeLeft -= 0.05;
		out = "0.05";
	}

	else if (changeLeft - 0.02 >= 0)
	{
		changeLeft -= 0.02;
		out = "0.02";
	}

	else
	{
		changeLeft -= 0.01;
		out = "0.01";
	}

	// Output coin used
	cout << out;

	// If there is still change left, run this function again
	if (changeLeft > 0)
	{
		cout << ", ";
		FindNextChange(changeLeft);
	}
}

// Takes in a float and rounds it to 2 decimal places
double Round(double val)
{
	int castInt;

	// Multiply by 100 so everything we want is to the left of the decimal point
	val *= 100;
	// Add .5 for rounding purposes
	val += .5;
	// Cast to int to remove decimal places
	castInt = val;
	// Divide by 100 to make a float again with 2 max decimal places
	val = double(castInt) / 100;

	return val;
}
#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

/// Vending machine functions

// Function that takes in an amount of money and returns that amount divided up into change
bool VendingMachine();

void FindNextChange(double);

double Round(double);


/// Delivery driver functions & classes

// Function that finds the optimum order in which a delivery driver should do his jobs

struct Job
{
	int fee;

	int due;

	bool done;
};

bool DeliveryDriver();

int FindNextJob(vector<Job>*, int);

vector<Job> MakeJobTable(int);
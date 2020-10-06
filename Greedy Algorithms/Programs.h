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

struct Job
{
	int fee;

	int due;

	bool done;

	void ReGenerateItem();
};

// Function that finds the optimum order in which a delivery driver should do his jobs
bool DeliveryDriver();

int FindNextJob(vector<Job>*, int);

/// Inventory manager functions and classes

struct Item
{
	int value;

	int weight;

	float heuristic;

	bool canBeHeld;

	//void ReGenerateItem();
};

//bool InventoryManager();

//int FindNextItem(vector<Item>*, int, int);


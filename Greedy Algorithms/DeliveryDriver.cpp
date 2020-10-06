#include "Programs.h"

bool DeliveryDriver()
{
	vector<Job> jobTable;
	for (int i = 0; i < 12; i++)
		jobTable.push_back(Job());

	while (true)
	{
		cout << "Generating job table..." << endl;
		cout << "Job Table: (ID, fee, due)" << endl;
		for (int i = 0; i < jobTable.size(); i++)
		{
			jobTable[i].ReGenerateItem();
			cout << i << "   " << jobTable[i].fee << "   " << jobTable[i].due << endl;
		}

		cout << "Money made " << FindNextJob(&jobTable, 0) << endl;

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

int FindNextJob(vector<Job>* jobTable, int time)
{
	int bestJobID = -1;

	for (int i = time+1; i < 9; i++)
	{
		for (int j = 0; j < jobTable->size(); j++)
		{
			if (jobTable->operator[](j).due == i && jobTable->operator[](j).done == false)
			{
				if (bestJobID == -1)
					bestJobID = j;

				else if (jobTable->operator[](bestJobID).fee < jobTable->operator[](j).fee)
					bestJobID = j;
			}
		}


		if (bestJobID != -1)
			break;
	}

	if (bestJobID == -1)
	{
		cout << "End of day reached or no jobs available" << endl;
		return 0;
	}

	cout << "Doing job ID " << bestJobID << " for " << jobTable->operator[](bestJobID).fee << " at timeslot " << time << endl;

	jobTable->operator[](bestJobID).done == true;

	return jobTable->operator[](bestJobID).fee + FindNextJob(jobTable, time+1);
}

void Job::ReGenerateItem()
{
	fee = rand() % 51;
	due = rand() % 8 + 1;
	done = false;
}
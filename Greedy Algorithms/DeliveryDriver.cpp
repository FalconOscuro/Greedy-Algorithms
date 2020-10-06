#include "Programs.h"

bool DeliveryDriver()
{
	while (true)
	{
		cout << "Generating job table..." << endl;
		vector<Job> jobTable = MakeJobTable(12);
		cout << "Job Table: (ID, fee, due)" << endl;

		for (int i = 0; i < jobTable.size(); i++)
			cout << i << "   " << jobTable[i].fee << "   " << jobTable[i].due << endl;

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

vector<Job> MakeJobTable(const int tableSize)
{
	vector<Job> jobTable;
	Job newJob;

	for (int i = 0; i < tableSize; i++)
	{
		newJob.fee = rand() % 51;
		newJob.due = rand() % 8 + 1;
		newJob.done = false;

		jobTable.push_back(newJob);
	}

	return jobTable;
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
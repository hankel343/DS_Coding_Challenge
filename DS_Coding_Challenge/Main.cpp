#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
	ofstream outFile;
	outFile.open("Primes.txt");

	chrono::time_point<chrono::system_clock> start;
	chrono::time_point<chrono::system_clock> end;
	chrono::duration<float> elapsed;

	vector<int> nPrimes;
	bool bIsPrime = true;

	start = chrono::system_clock::now();
	for (int i = 1; i <= 1000000; i++)
	{
		bIsPrime = true;
		for (int j = 2; j < i && bIsPrime; j++)
		{
			if (i % j == 0)
				bIsPrime = false;
		}

		if (bIsPrime)
			nPrimes.push_back(i);

	}

	end = chrono::system_clock::now();
	elapsed = end - start;

	cout << "Calculation runtime: " << elapsed.count() << endl;

	for (int i = 0; i < nPrimes.size(); i++)
	{
		if (i != 0 && i % 10 == 0)
			outFile << nPrimes[i] << endl;
		else
			outFile << nPrimes[i] << " ";
	}


	return 0;
}
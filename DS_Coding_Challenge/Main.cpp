#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ofstream outFile;
	outFile.open("Primes.txt");

	vector<int> nPrimes;
	bool bIsPrime = true;

	for (int i = 1; i <= 10000; i++)
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


	for (int i = 0; i < nPrimes.size(); i++)
	{
		if (i != 0 && i % 10 == 0)
			outFile << nPrimes[i] << endl;
		else
			outFile << nPrimes[i] << " ";
	}


	return 0;
}
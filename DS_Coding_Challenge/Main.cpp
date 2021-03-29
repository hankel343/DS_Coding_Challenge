#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> nPrimes;
	bool bIsPrime = true;

	for (int i = 1; i <= 100; i++)
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

	cout << "Primes between 1 and 100: \n";
	for (int i = 0; i < nPrimes.size(); i++)
	{
		if (i != 0 && i % 10 == 0)
			cout << nPrimes[i] << endl;
		else
			cout << nPrimes[i] << " ";
	}


	return 0;
}
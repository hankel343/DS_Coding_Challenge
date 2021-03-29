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
		//Assume number is prime to begin with.
		bIsPrime = true;
		for (int j = 2; j < i && bIsPrime; j++)
		{
			if (i % j == 0) //Demonstrated to not be a prime number.
				bIsPrime = false;
		}

		if (bIsPrime) //If control makes it through the inner loop without having set bIsPrime to false, i is a prime number.
			nPrimes.push_back(i);
	}

	//Calculation is slowed down by prime numbers that have to have each number up to itself tested.
	//Composite numbers take less time to find because as soon as a mod of 0 is found it is known that i is not a prime number.
	//One approach that might cut down on computational time is using an array of found composite numbers to test i.

	end = chrono::system_clock::now();
	elapsed = end - start;

	cout << "Calculation runtime: " << elapsed.count() << endl;
	cout << nPrimes.size() - 1 << " primes were found.\n";

	for (int i = 0; i < nPrimes.size(); i++)
	{
		if (i != 0 && i % 10 == 0)
			outFile << nPrimes[i] << endl;
		else
			outFile << nPrimes[i] << " ";
	}


	return 0;
}
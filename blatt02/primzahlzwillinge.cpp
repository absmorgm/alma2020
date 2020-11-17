#include <iostream>
#include <vector>

const int LIMIT = 100;

using namespace std;

int findTwinPrimes(int limit, vector<pair<int, int> > list)
{
    vector<bool> is_prime(limit + 1, true);
	int twinPrimeCount = 0;

    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) {
		    if (i > 0 && is_prime[i - 2]) {
				twinPrimeCount++;
				list.push_back(make_pair(i, i - 2));
			}
	      
            for (int j = i; j <= limit / i; ++j) {
                is_prime[i * j] = false;
            }
        }
    }
	return twinPrimeCount;
}


int main()
{
		vector<pair<int, int> > twinPrimeList;

		cout << "Es gibt: " << findTwinPrimes(LIMIT, twinPrimeList) << " Primzahlzwillinge bis " << LIMIT << endl;

		cout << "Auflistung: " << endl;
		cout << "Size " << twinPrimeList.size();

		for (const auto& pair: twinPrimeList) {
				cout << "(" << pair.first << "," << pair.second << ")" << endl;
		}
}

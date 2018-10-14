//primeTillN.cpp

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int N;

	cin >> N;
	bool prime = true;
	for (int i = 2; i < N; ++i)
	{	prime = true;
		for (int j = 2; j <= pow(i, 0.5); ++j)
		{
			if ( i != 2 && i % j == 0 )
			{
				prime = false;
				break;
			}
		}
		if (prime == true)
		{
			cout << i << " ";
		}
	}
}
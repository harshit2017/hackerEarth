//roy.cpp

#include<iostream>
using namespace std;
int main()
{

	long int L , N ;
	cin >> L >> N;
	long int foto[2 * N] = {};
	for (int i = 0; i < 2 * N; ++i)
	{
		cin >> foto[i];
	}
	for (int i = 0; i < 2 * N; i = i + 2)
	{

		if (foto[i] < L || foto[i + 1] < L)
		{
			cout << "UPLOAD ANOTHER\n";
		}
		else
		{
			if (foto[i] == foto[i + 1])
			{
				cout << "ACCEPTED\n";
			}
			else
			{
				cout << "CROP IT\n";
			}
		}

	}
	return 0;

}
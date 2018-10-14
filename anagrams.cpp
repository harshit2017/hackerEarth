//anagrams.cpp
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	string a, b;
	int t;

	cin >> t ;

	for (int j = 0; j < t; j++)
	{	cin >> a >> b;
		int counta[26] = {0}, countb[26] = {0};
		for (int i = 0; a[i] != '\0'; i++)
		{
			++counta[a[i] - 'a'];
		}

		for (int i = 0; b[i] != '\0'; i++)
		{
			++countb[b[i] - 'a'];
		}
		int result = {0};
		for (int i = 0; i < 26; ++i)
		{
			result += abs(counta[i] - countb[i]);
		}
		cout << result << "\n";

	}



}
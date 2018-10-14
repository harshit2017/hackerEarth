//2strings.cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	int t;

	cin >> t ;

	for (int j = 0; j < t; j++)
	{	cin >> a >> b;
		int count[26] = {0};
		for (int i = 0; a[i] != '\0'; i++)
		{
			++count[a[i] - 'a'];
		}

		for (int i = 0; b[i] != '\0'; i++)
		{
			--count[b[i] - 'a'];
		}

		int flag = 1;
		for (int i = 0; i < 26; ++i)
		{
			if (count[i] != 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)cout << "YES\n";
		else cout << "NO\n";

	}



}
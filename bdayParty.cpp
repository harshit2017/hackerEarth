//bdayParty.cpp
#include<iostream>
using namespace std;
int main()
{
	int t, N, M;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{	cin >> N >> M;
		if (M % N == 0)cout << "Yes\n";
		else cout << "No\n";
	}
}
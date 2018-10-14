//life.cpp
#include<iostream>
using namespace std;
int main()
{
	int a[100];
	int i = 0;
	do {
		cin >> a[i];
		++i;
	} while (a[i - 1] != 42);
	int j = 0;
	while (a[j] != 42)
	{
		cout << a[j] << "\n";
		++j;
	}
}
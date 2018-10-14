//factorial.cpp

#include<iostream>
using namespace std;

int main()
{
	int fact = 1, N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		fact *= i;
	}
	cout << fact;
}
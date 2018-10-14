//findProduct.cpp
#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	long long int a[N], product = 1;
	for (int i = 0; i < N; i++) {cin >> a[i];}
	for (int i = 0; i < N; ++i)
	{
		product = (product * a[i]) % 1000000007;
	}
	cout << product;
}
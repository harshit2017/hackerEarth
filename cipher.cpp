//cipher.cpp
#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		char c = s[i];
		if (isupper(c))
		{	char up = ((c - 'A') + k) % 26 + 'A';
			cout << up;
		}
		else if (islower(c))
		{	char lo = ((c - 'a') + k) % 26 + 'a';
			cout << lo;
		}
		else if (isdigit(c))
		{	char dig = ((c - '0') + k) % 10 + '0';
			cout << dig;
		}
		else
		{
			cout << c;
		}
	}
}



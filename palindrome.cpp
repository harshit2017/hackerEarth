//palindrome.cpp
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	char s[100];
	cin >> s;
	int i = 0, j = strlen(s) - 1;
	int flag = 0;
	while (i <= j )
	{
		if (s[i] != s[j])flag = 1;
		++i, --j;
	}
	if (flag == 0)cout << "YES";
	else cout << "NO";

}

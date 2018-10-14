//toggleString.cpp
#include<iostream>
int main()
{
	char str[100];
	std::cin >> str;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if ('A' < str[i] < 'Z')str[i] = str[i] + 32;
		else str[i] = str[i] - 32;
	}
	std::cout << str;
}
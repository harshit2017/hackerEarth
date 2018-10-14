//seating.cpp
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	int N;
	cin >> t ;
	for (int i = 0; i < t; ++i)
	{
		cin >> N;
		int seatNo, n = ceil((float)N / 12);
		switch (n)
		{
		case 1: seatNo = 13 - N;
			break;

		case 2: seatNo = 37 - N;
			break;

		case 3: seatNo = 61 - N;
			break;


		case 4: seatNo = 85 - N;
			break;

		case 5: seatNo = 109 - N;
			break;

		case 6: seatNo = 133 - N;
			break;

		case 7: seatNo = 157 - N;
			break;

		case 8: seatNo = 181 - N;
			break;
		default: seatNo = 205 - N;
			break;

		}
		if (abs(seatNo - N) == 1 || abs(seatNo - N) == 11)
		{cout << seatNo << " WS\n";}
		else if (abs(seatNo - N) == 3 || abs(seatNo - N) == 9)
		{cout << seatNo << " MS\n";}
		else
		{cout << seatNo << " AS\n";}
	}
}

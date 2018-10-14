#include <iostream>

using namespace std;
unsigned long long check(unsigned long long x)
{
    unsigned long long t = 1;
    for (; t * t <= x; t <<= 1)
        ;
    if (x / t >= t / 2)
        return x - x / t;
    else
        return x - t / 2 + 1;
}
int main()
{

    int t, i, j;
    cin >> t;

    for (i = 1; i <= t; i++)
    {
        unsigned long long x;
        cin >> x;
        cout << check(x) << '\n';
    }
}
#include <iostream>
using namespace std;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        long N;
        int count1 = 0;
        cin >> N;
        while (N)
        {
            if (N % 2)
                ++count1;
            N /= 2;
        }
        cout << count1 << '\n';
    }
}
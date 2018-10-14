#include <iostream>
using namespace std;

void sort(int a[], int n)
{
    int c[8] = {}, b[n];
    for (int i = 0; i < n; i++)
        c[a[i]]++; //elements which are equal to i

    for (int i = 1; i < 8; i++)
        c[i] = c[i] + c[i - 1]; //elements which are less than equal to i

    for (int i = n - 1; i >= 0; i--)
    {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    //copy back to a
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, n);

    for (int i = 0; i < n; i++)
        cout << a[i];
}
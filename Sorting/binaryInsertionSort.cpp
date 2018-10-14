#include <iostream>
using namespace std;

int search(int key, int a[], int be, int end)
{
    int mid = (be + end) / 2;

    if (be >= end)
        return (key > a[be]) ? be + 1 : be;
    if (a[mid] == key)
        return mid + 1;
    if (a[mid] < key)
        return search(key, a, mid + 1, end);
    return search(key, a, be, mid - 1);
}

void sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int pos = search(key, a, 0, i - 1);
        for (int j = i; j > pos; j--)
            a[j] = a[j - 1];
        a[pos] = key;
    }
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

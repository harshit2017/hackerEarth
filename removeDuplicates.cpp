#include <iostream>
#include <set>
//#include <map>

using namespace std;

void removeduplicates(int arr[], int &n)
{
    set<int> m;

    //building map from the set
    for (int i = 0; i < n; i++)
        m.insert(arr[i]);
    int i = 0;
    for (set<int>::iterator it = m.begin(); it != m.end(); it++)
    {
        arr[i] = *it;
        ++i;
    }
    n = i;
}

int main()
{
    int arr[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    removeduplicates(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }
}
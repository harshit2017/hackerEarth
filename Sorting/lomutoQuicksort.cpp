#include <iostream>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int be, int end)
{
    int pi = a[end];
    int i = be - 1;
    for (int j = be; j <= end - 1; j++)
    {
        if (a[j] < pi)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[end]);
    return i + 1;
}

int partition_r(int a[], int be, int end)
{
    srand(time(NULL));
    int random = be + rand() % (end - be);
    swap(&a[random], &a[end]);
    return partition(a, be, end);
}

void quicksort(int a[], int be, int end)

{
    if (be < end)
    {
        int pi = partition_r(a, be, end);
        quicksort(a, be, pi - 1);
        quicksort(a, pi + 1, end);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i];
    return 0;
}

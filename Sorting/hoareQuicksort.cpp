//in hoare the pivot can change and it has 3 times fewer number of swaps as compared to lomuto.
//and creates better partition whenn number of elemenets are equal.
#include <iostream>
#include <ctime>
using namespace std;
int Partition(int[], int, int);
// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// int partition(int a[], int be, int end)
// {
//     int pivot = a[be];
//     int i = be - 1, j = end + 1;
//     while (1)
//     { //find the leftmost element greater than pivot
//         do
//         {
//             i++;
//         } while (a[i] > pivot);

//         //find the rightmost element smaller than pivot

//         do
//         {
//             j--;
//         } while (a[j] < pivot);

//         if (i >= j)
//             return j;
//         swap(&a[i], &a[j]);
//         }
// }

// int partition_r(int a[], int be, int end)
// {
//     srand(time(NULL));
//     int random = be + rand() % (end - be);
//     swap(&a[random], &a[be]);
//     return partition(a, be, end);
// }

void quicksort(int a[], int be, int end)

{
    if (be < end)
    {
        int pi = Partition(a, be, end);
        quicksort(a, be, pi);
        quicksort(a, pi + 1, end);
    }
}

int Partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low - 1;
    int j = high + 1;
    while (1)
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        //searching which is greater than pivot
        do
        {
            j--;
        } while (a[j] > pivot);
        //searching element smaller than pivot

        if (i >= j)
            return j;

        swap(a[i], a[j]);
    }
}

// Quicksort routine
// void QuickSort(int a[], int low, int high)
// {
//     // base condition
//     if(low >= high)
//         return;

//     // rearrange the elements across pivot
//     int pivot = Partition(a, low, high);

//     // recurse on sub-array containing elements that are less than pivot
//     QuickSort(a, low, pivot);

//     // recurse on sub-array containing elements that are more than pivot
//     QuickSort(a, pivot + 1, high);
// }

int main()
{
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i];
}
#include <iostream>
using namespace std;
//if elements are in range 1...n^2.counting sort not applicable.radix sort increases the range

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countingsort(int arr[], int n, int exp)
{
    int output[n]; //output array
    int i, count[10] = {};
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    //to know maximum no of digits
    int m = getMax(arr, n);

    //do counting sort for every digit starting from the least significant digit
    for (int exp = 1; m / exp > 0; exp *= 10)
    {

        countingsort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    radixsort(arr, 8);
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
}
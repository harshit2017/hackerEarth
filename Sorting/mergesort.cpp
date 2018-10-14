#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r)
{
    //make 2 temporary arrays;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int la[n1], ra[n2];
    //cout << a[0];
    //copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        la[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        ra[i] = a[mid + 1 + i];
    //cout << la[0];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (la[i] <= ra[j])
        {
            a[k] = la[i];
            i++;
        }
        else
        {
            a[k] = ra[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        //cout << la[i] << "i\n";
        a[k] = la[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = ra[j];
        j++;
        k++;
        //cout << "j" << a[k];
    }
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        //    cout << a[0] << "\n";

        int mid = (l + r) / 2;
        mergesort(a, l, mid);     //divide leftsubarray
        mergesort(a, mid + 1, r); //divide right subarray
        merge(a, l, mid, r);      //merge the two subarrays
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //cout << a[0];
    mergesort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i];
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
//useful when data is uniformly distributed in vector
void bucketsort(float arr[], int n)
{
    //create n empty buckets
    vector<float> b[n]; //creates an array of vectors
    for (int i = 0; i < n; i++)
    {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }

    //sort buckets
    for (int i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
    }
    //concatenate all buckets in arr
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < b[i].size(); j++)
        {
            arr[index++] = b[i][j];
        }
    }
}

int main()
{
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketsort(arr, 6);

    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}
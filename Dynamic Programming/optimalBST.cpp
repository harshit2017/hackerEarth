//optimalBST.cpp

#include<iostream>
#include <climits>

using namespace std;

int sum(int freq[],int i,int j)
{
    int s = 0;
    for (int k = i; k <=j; k++)
        s += freq[k];
    return s;
}

//element of matrix represents expected cost of the tree

int optimalBST(int keys[],int freq[],int n)
{
//create an expected cost matrix
    int cost[n][n];

    for(int i=0; i<n; i++) //for single key cost =frequency
        cost[i][i]=freq[i];
    // cout<<cost[2][2]<<endl;
    for(int l=2; l<=n; l++)
    {
        for(int i=0; i<=n-l+1; i++)
        {
            int j=i+l-1;
            cost[i][j]=INT_MAX;

            for(int r=i; r<=j; r++)
            {
                int ecost = ((r > i)? cost[i][r-1]:0) +
                            ((r < j)? cost[r+1][j]:0) +
                            sum(freq, i, j);

                if(ecost<cost[i][j])cost[i][j]=ecost;
            }
        }
    }
    // cout<<cost[2][2]<<endl;
    return cost[0][n-1];

}

int main()
{
    int keys[]= {10,12,20};
    int freq[]= {34,8,50};

    int n = sizeof(keys)/sizeof(keys[0]);
    cout<<optimalBST(keys,freq,n);

}

//it is just like matrix chain
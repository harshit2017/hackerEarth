//marixChain.cpp
#include <iostream>
#include <climits>
#include <algorithm>
#define m 100

using namespace std;

//Matrix chain counts the number of scalar multiplications

int MatrixChain(int p[],int i,int j)
{   //i=j => only one matrix
    if(i==j)return 0;

    int min=INT_MAX;
    int count;

    for(int k=i; k<j; k++)
    {
        count=MatrixChain(p,i,k)+MatrixChain(p,k+1,j)+p[i-1]*p[k]*p[j];

        if(count<min)min=count;
    }
    return min;
}

//using memoisation
int a[m][m];

int memoChain(int p[],int i,int j)
{
    if(a[i][j]!=INT_MAX)return a[i][j];

    if(i==j) {

        a[i][j]=0;
    }


    else {
        int count;
        for(int k=i; k<j; k++)
        {
            count=memoChain(p,i,k)+memoChain(p,k+1,j)+p[i-1]*p[k]*p[j];

            if(count<a[i][j]) {
                a[i][j]=count;
            }

        }
    }

    return a[i][j];


}


//tabulation method
int tabulation(int p[],int n)
{
    //scalar multiplications is zero when there is only one matrix
    for(int i=1; i<n; i++)
    {
        a[i][i]=0;
    }

    for(int l=2; l<n; l++) //l is the chain length

    {
        for(int i=1; i<n-l+1; i++)//this loop is for starting point
        {
            int j=i+l-1;
            a[i][j]=INT_MAX;

            for(int k=i; k<=j-1; k++)
            {   //cout<<"hello";
                int count=a[i][k]+a[k+1][j]+p[i-1]*p[k]*p[j];

                if(count<a[i][j])a[i][j]=count;
                cout<<a[i][j];

            }
        }
    }

    return a[1][n-1];
}


int main(int argc, char const *argv[])
{
    int arr[]= {1,2,3,4};//a is an array containing dimensions of the matrix
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"Min Number of Multiplications - "<<MatrixChain(arr,1,n-1);


    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)a[i][j]=INT_MAX;
    }

    cout<<"\nMemoised Matrix Chain- "<<memoChain(arr,1,n-1);

    cout<<"\nTabulation Method- "<<tabulation(arr,n);


}

// we will solve problems in which has smallest size and then build upon the optimal soln
//first solve problem in wich chain length l=1
//then solve l=2
//then solve l=3;
//i will have loop which goes from 1->n-1

// I need a loop for starting point i.e i 1->n-l
//j is the final index
//remember we need to iterate the 'm' matrix diagonally
#include<iostream>
#define MAX 100
using namespace std;
int c[MAX][MAX];
//Recursive formula to calculate   C(n,k)=C(n-1,k-1)+C(n-1,k)
int coefficient(int n,int k)
{
    if(k==0 || k==n )
        return 1;
    return coefficient(n-1,k-1) + coefficient(n-1,k);
}
//Dynamic Programming
// Top down approach which known as Memorization

void initialize()
{
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            c[i][j]=0;
}
int coef(int n,int k)
{
    // if(c[n]==0)
    // {
    //     if(k==0 || k==n)
    //         c[n] = 1;
    //     else
    //         c[n] = coef(n-1,k-1) + coef(n-1,k);
    // }
    // return c[n];
    if(k==0 || k==n )
        return 1;
    if(c[n][k]!=0)
        return c[n][k];
    return c[n][k]=coef(n-1,k-1) + coef(n-1,k);
}

//tabulation method

int tabu(int n,int k)
{
    int coef[n+1][k+1];


    // cout<<"hello"<<coef[n][k];
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=min(i,k); j++)
        {
            if(j==0||j==i)
                coef[i][j]=1;
            else
                coef[i][j]=coef[i-1][j-1]+coef[i-1][j];
        }
    }

    return coef[n][k];
}


int main()
{
    int n=5,k=3;
    cout<<"Coefficient = :"<<coefficient(n,k);
    cout<<endl;
    cout<<"Coefficient = :"<<coef(n,k);

    cout<<endl<<tabu(n,k);
}

//longestCommonSubseq.cpp
#include <iostream>
#include <algorithm>
#define size 100
using namespace std;

//simple recursion
int simpleLcs(char * x,char * y,int i,int j)
{
    if(i==0||j==0)return 0;
    //if last are equal
    if(x[i-1]==y[j-1])return 1+simpleLcs(x,y,i-1,j-1);

    else
        return max(simpleLcs(x,y,i,j-1),simpleLcs(x,y,i-1,j));

}

//using memoisation
int c[size][size];
int memo(char *x,char *y,int i,int j)
{
    if(i==0||j==0)return 0;
    if(c[i-1][j-1]!=-1)return c[i-1][j-1];
    //if last are equal
    if(x[i-1]==y[j-1])return c[i-1][j-1]=1+simpleLcs(x,y,i-1,j-1);

    else
        return c[i-1][j-1]=max(simpleLcs(x,y,i,j-1),simpleLcs(x,y,i-1,j));
}

//using tabulation
int tabu(char *x, char *y,int i,int j)
{
    for(int m=0; m<i; m++)
    {
        for(int n=0; n<j; n++)
        {
            if(m==0||n==0)c[m][n]=0;//here m and n are length of strings

            else if(x[m-1]==y[n-1])c[m][n]=1+c[m-1][n-1];

            else c[m][n]=max(c[m-1][n],c[m][n-1]);
        }
    }

    return c[i-1][j-1];
}

int main(int argc, char const *argv[])
{
    char a[]="AGGTAB";
    char b[]="GXTXAYB";

    cout<<simpleLcs(a,b,6,7);

    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            c[i][j]=-1;

    cout<<"\n"<<memo(a,b,6,7);

    cout<<"\n"<<tabu(a,b,6,7);
}

//this ques is pretty easy because we traverse the array traditionally
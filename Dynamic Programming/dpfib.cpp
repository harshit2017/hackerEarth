//dpfib.cpp

#include<iostream>
#include <algorithm>//to use fill function
using namespace std;

int memo[1000];

int fib(int n) {
    if(n<=0)return 0;
    if(n==1)return 1;
    if(memo[n]!=-1)return memo[n];
    return memo[n]=fib(n-1)+fib(n-2);
}

main()//no return type means int
{
    int n;
    cin>>n;
    fill(memo,memo+n+1,-1);//fill with value -1
    int ans=fib(n);
    cout<<ans;
}

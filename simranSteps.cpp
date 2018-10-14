#include <iostream>
using namespace std;

int count;


int stairs(int N)
{
    if(N==1)return 1;
    if(N==2)return 2;
    if(N==3)return 4;

    return stairs(N-1)+stairs(N-2)+stairs(N-3);
}



int main()
{
    int N;
    cin >> N;
    cout<<stairs(N);
    
}
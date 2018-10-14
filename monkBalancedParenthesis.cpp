#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> paren;
    int length = 0;
    int n;
    cin >> n;
    int a;
    cin >> a;
    paren.push(a);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a;

        if (paren.empty() == false && a != -paren.top())
            paren.push(a);
        else
        {
            paren.pop();
        }
    }
}
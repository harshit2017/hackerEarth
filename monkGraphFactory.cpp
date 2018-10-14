#include <iostream>
using namespace std;

int main()
{
    int Nver;
    cin >> Nver;
    int sumDeg = 0, d;
    for (int i = 0; i < Nver; i++)
    {
        cin >> d;
        sumDeg += d;
    }

    //handshaking lemma
    //sum of degrees of vertice in trees =2*(edges) where edges=nVer-1
    if (sumDeg != 2 * (Nver - 1))
        cout << "No";
    else
        cout << "Yes";
}
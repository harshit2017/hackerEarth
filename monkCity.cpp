#include <iostream>
#include <set>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;

    while (testCase--)
    {
        int roads;
        cin >> roads;
        set<int> city;
        for (int i = 0; i < roads; i++)
        {
            int c1, c2;
            cin >> c1 >> c2;
            city.insert(c1);
            city.insert(c2);
        }

        cout << city.size() << "\n";
    }
}
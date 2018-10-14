#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ti, di;
    vector<pair<int, int>> order;
    for (int i = 1; i <= n; i++)
    {
        cin >> ti >> di;
        order.push_back(make_pair(ti + di, i));
    }
    sort(order.begin(), order.end());

    for (int i = 0; i < n; i++)
    {
        cout << order[i].second << " ";
    }
}
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    int nVer, nEdge, pos;
    cin >> nVer >> nEdge >> pos;

    vector<int> val;
    for (int i = 1; i <= nVer; i++)
    {
        cin >> val[i];
    }
    vector<list<int>> adjList;

    for (int i = 1; i <= nEdge; i++)
    {
        int nod1, nod2;
        cin >> nod1 >> nod2;
        adjList[nod1].push_back(nod2);
        adjList[nod2].push_back(nod1);
    }

    //sorting the adjacency list in decreasing order

    for (int i = 1; i <= nVer; i++)
    {
        sort(adjList[i].begin())
    }
}
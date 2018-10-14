#include <list>
#include <set>
#include <iostream>
using namespace std;

class Graph
{
    int nDogs;
    list<int> *doglist; //list of dogs met by a dog
    typedef list<int>::iterator lit;

  public:
    Graph(int n)
    {
        nDogs = n;
        doglist = new list<int>[nDogs + 1];
    }

    void meet(int d1, int d2)
    {
        doglist[d1].push_back(d2);
        doglist[d2].push_back(d1);
    }

    int maxDogNotMet()
    {
        set<int> notMet;
        for (int i = 1; i <= nDogs; i++)
        {
            lit it = doglist[i].begin();
            int j = i + 1;
            for (it; it != doglist[i].end() && j <= nDogs; it++, j++)
            {
                if (*it != j)
                {
                    notMet.insert({i, j});
                }
            }
        }
        return notMet.size();
    }
    ~Graph()
    {
        delete[] doglist;
    }
};

int main()
{
    int n; //number of dogs in the  party
    cin >> n;
    //hash needs to find the max num of dogs who have not met in the party.
    Graph g(n);

    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        while (m--)
        {
            int dogMet;
            cin >> dogMet;
            g.meet(i, dogMet);
        }
    }

    cout << g.maxDogNotMet();
}

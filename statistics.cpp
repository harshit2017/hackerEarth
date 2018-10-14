#include <iostream>
#include <map>
#include <set>
using namespace std;

int main()
{
    int N, football = 0, maxFreq = 1;
    cin >> N;
    set<string> personName;
    map<string, int> favSport;
    pair<map<string, int>::iterator, bool> ret;
    pair<set<string>::iterator, bool> ret1;
    while (N--)
    {
        int freq = 1;
        string sportName, name;
        cin >> name >> sportName;
        ret1 = personName.insert(name);

        if (ret1.second == true)
        {
            ret = favSport.insert(pair<string, int>(sportName, freq));
            if (ret.second == false)
            {
                ret.first->second++;
                if (maxFreq < ret.first->second)
                    maxFreq = ret.first->second;
            }
        }
    }

    string maxPlayed;
    int flag = 0;
    for (map<string, int>::iterator it = favSport.begin(); it != favSport.end(); it++)
    {

        if (maxFreq == it->second && flag == 0)
        {
            maxPlayed = it->first;
            flag = 1;
        }

        if (it->first == "e")
            football = it->second;
    }

    cout << maxPlayed << "\n";

    cout << football;
}
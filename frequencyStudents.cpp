#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, int> studentsFreq;
    while (N--)
    {
        string name;
        cin >> name;
        int freq = 1;
        pair<map<string, int>::iterator, bool> ret;
        ret = studentsFreq.insert(pair<string, int>(name, freq));
        if (ret.second == false)
            ret.first->second++;
    }
    for (map<string, int>::iterator it = studentsFreq.begin(); it != studentsFreq.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }
}
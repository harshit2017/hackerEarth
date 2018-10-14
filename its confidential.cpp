#include <iostream>
#include <vector>

using namespace std;

void encrypted(vector<char> str, vector<char> &decision, int be, int end)
{
    //cout << i << "\n";

    if (be > end)
    {
        return;
    }

    int mid = (be + end) / 2;
    decision.push_back(str[mid]);//pushback adds elements if the last element is filled

    //cout << i << " ";

    //left substring
    encrypted(str, decision, be, mid - 1);
    //right substring
    encrypted(str, decision, mid + 1, end);
}

int main()
{
    int test;
    cin >> test;

    while (test--)
    {
        int N;
        cin >> N;

        vector<char> str(N, 0), decision(0, 0);
        //  cout << decision.size();
        char string[10001];
        cin >> string;
        str.assign(string, string + N);
        // cout << str.size();

        encrypted(str, decision, 0, N - 1);
        //auto-tpe will be deduced by the compiler from the initialiser
        for (auto const &i : decision)
        {
            cout << i;
        }
        cout << endl;
    }
}
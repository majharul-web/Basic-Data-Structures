#include <bits/stdc++.h>
using namespace std;

class Pairs
{
public:
    string S;
    int I;

    Pairs(string S, int I)
    {
        this->S = S;
        this->I = I;
    }
};

// Custom comparator
class CustomCompare
{
public:
    bool operator()(const Pairs s1, const Pairs s2)
    {
        if (s1.S == s2.S)
        {
            return s1.I < s2.I;
        }
        return s1.S > s2.S;
    }
};

int main()
{

    priority_queue<Pairs, vector<Pairs>, CustomCompare> pairsPQ;

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        string S;
        int I;
        cin >> S >> I;
        pairsPQ.push(Pairs(S, I));
    }

    while (!pairsPQ.empty())
    {
        Pairs topPair = pairsPQ.top();
        cout << topPair.S << " " << topPair.I;
        pairsPQ.pop();
        cout << endl;
    }

    return 0;
}

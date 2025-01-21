#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["shamim"] = 1;
    mp["ramim"] = 2;
    mp["karim"] = 3;
    mp["mahim"] = 4;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    if (mp.count("shamim"))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*
        pair<int, string> p;
        p = make_pair(10, "roll");

        cout << p.first << endl;
        cout << p.second << endl;
    */

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    cout << "printing pair of vector" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
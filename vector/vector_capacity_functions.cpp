#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    // cout << v.capacity() << endl;
    // v.push_back(10);
    // cout << v.capacity() << endl;
    // v.push_back(20);
    // cout << v.capacity() << endl;

    // vector increase capacity double for single entry

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    // v.clear(); // clear function set size 0 not delete element

    // cout << v[2] << endl;

    // v.resize(2);
    // v.resize(7);
    v.resize(7, 100);

    for (int i = 0; i < v.size(); i++)

    {
        cout << v[i] << endl;
    }

    return 0;
}
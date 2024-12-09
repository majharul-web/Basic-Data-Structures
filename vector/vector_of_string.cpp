#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter your vector length : " << endl;
    cin >> n;
    cin.ignore();

    vector<string> v(n);

    cout << "Enter your Name : " << endl;

    for (int i = 0; i < n; i++)

    {
        getline(cin, v[i]);
    }

    for (string s : v)
    {
        cout << s << endl;
    }

    return 0;
}
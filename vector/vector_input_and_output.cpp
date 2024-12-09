#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter your vector size : ";
    cin >> n;

    // vector<int> v(n);

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }

    vector<int> v;

    for (int i = 0; i < n; i++)

    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << "Your vector : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        set<int> A;
        while (N--)
        {
            int val;
            cin >> val;
            A.insert(val);
        }

        for (int val : A)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
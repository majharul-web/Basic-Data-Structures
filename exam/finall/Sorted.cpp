#include <bits/stdc++.h>
using namespace std;

void displayList(map<int, set<int>> list)
{
    for (auto it : list)
    {
        for (int val : it.second)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main()
{
    map<int, set<int>> list;
    int T;
    cin >> T;
    int index = 0;
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
        list.insert({index++, A});
    }
    displayList(list);

    return 0;
}
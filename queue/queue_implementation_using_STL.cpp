#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "front : " << q.front() << endl;
    cout << "back : " << q.back() << endl;
    cout << "size : " << q.size() << endl;
    cout << "empty before pop : " << (q.empty() == 1 ? "true" : "false") << endl;

    cout << "Queue : ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << "empty after pop : " << (q.empty() == 1 ? "true" : "false") << endl;

    return 0;
}

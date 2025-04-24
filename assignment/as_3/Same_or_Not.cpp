#include <bits/stdc++.h>
using namespace std;

string isEqualStackAndQueue(stack<int> &st, queue<int> &q)
{

    if (st.size() != q.size())
    {
        return "NO";
    }

    while (!st.empty() && !q.empty())
    {
        if (st.top() != q.front())
        {
            return "NO";
        }
        st.pop();
        q.pop();
    }

    return "YES";
}

int main()
{

    int N, M;
    cin >> N >> M;

    stack<int> st;
    while (N--)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    queue<int> q;
    while (M--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << isEqualStackAndQueue(st, q) << endl;

    return 0;
}

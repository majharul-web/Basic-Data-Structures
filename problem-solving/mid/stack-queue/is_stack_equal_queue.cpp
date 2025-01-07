#include <bits/stdc++.h>
using namespace std;

bool isStackQueueSame(stack<int> st, queue<int> q)
{
    // Compare sizes first
    if (st.size() != q.size())
    {
        return false;
    }

    // Compare elements in order of removal
    while (!st.empty() && !q.empty())
    {
        if (st.top() != q.front())
        {
            return false;
        }
        st.pop();
        q.pop();
    }

    return true;
}

int main()
{
    int n, m;

    // Input for stack
    cin >> n;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    // Input for queue
    cin >> m;
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    // Check if the stack and queue are the same
    if (isStackQueueSame(st, q))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

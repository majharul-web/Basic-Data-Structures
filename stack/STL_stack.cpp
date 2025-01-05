#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
        }

    return 0;
}
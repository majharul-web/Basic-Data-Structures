#include <bits/stdc++.h>
using namespace std;

string isValidString(string s)
{

    stack<char> st1, st2;

    for (char c : s)
    {
        st1.push(c);
    }

    while (!st1.empty())
    {
        char top = st1.top();
        st1.pop();

        if (!st2.empty() && st2.top() != top)
        {
            st2.pop();
        }
        else
        {
            st2.push(top);
        }
    }

    return st2.empty() ? "YES" : "NO";
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        cout << isValidString(S) << endl;
    }

    return 0;
}

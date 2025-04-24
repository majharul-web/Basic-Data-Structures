#include <bits/stdc++.h>
using namespace std;

string isValidString(string S)
{
    stack<char> st;

    for (char C : S)
    {

        if (!st.empty() && st.top() != C)
        {
            st.pop();
        }
        else
        {
            st.push(C);
        }
    }

    return st.empty() ? "YES" : "NO";
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

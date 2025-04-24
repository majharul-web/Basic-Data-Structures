#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isEmptyAfterElimination(const string &binaryString)
{
    stack<char> st;

    for (char c : binaryString)
    {
        if (!st.empty() && st.top() == '0' && c == '1')
        {
            // Eliminate the '0' and the current '1'
            st.pop();
        }
        else
        {
            // Push the current character onto the stack
            st.push(c);
        }
    }

    // If the stack is empty, the string is empty after all eliminations
    return st.empty();
}

int main()
{
    int t; // Number of test cases
    cin >> t;

    while (t--)
    {
        string binaryString;
        cin >> binaryString;

        if (isEmptyAfterElimination(binaryString))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st1, st2;

    st1.push(5);
    st2.push(10);

    // Swap using std::swap
    std::swap(st1, st2);

    cout << "Stack 1 top: " << st1.top() << endl; // Output: 10
    cout << "Stack 2 top: " << st2.top() << endl; // Output: 5

    return 0;
}

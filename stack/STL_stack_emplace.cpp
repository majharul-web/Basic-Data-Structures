#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;

    // Use emplace to add elements
    st.emplace(10);
    st.emplace(20);
    st.emplace(30);

    // Display the top element
    cout << "Top element: " << st.top() << endl; // Output: 30

    return 0;
}

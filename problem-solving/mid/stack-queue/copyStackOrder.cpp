#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Input the stack
    stack<int> originalStack;
    while (n--)
    {
        int val;
        cin >> val;
        originalStack.push(val);
    }

    // Use a temporary stack to reverse the order
    stack<int> tempStack;
    while (!originalStack.empty())
    {
        tempStack.push(originalStack.top());
        originalStack.pop();
    }

    // Print the elements of the temporary stack to maintain insertion order
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }

    cout << endl;
    return 0;
}

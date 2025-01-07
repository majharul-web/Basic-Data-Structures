#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int n;

    cin >> n;

    // Input the queue
    queue<int> originalQueue;
    while (n--)
    {
        int val;
        cin >> val;
        originalQueue.push(val);
    }

    // Use a stack to reverse the order
    stack<int> tempStack;
    while (!originalQueue.empty())
    {
        tempStack.push(originalQueue.front());
        originalQueue.pop();
    }

    // Create another queue and fill it with elements from the stack
    queue<int> reversedQueue;
    while (!tempStack.empty())
    {
        reversedQueue.push(tempStack.top());
        tempStack.pop();
    }

    // Print the reversed queue
    while (!reversedQueue.empty())
    {
        cout << reversedQueue.front() << " ";
        reversedQueue.pop();
    }

    cout << endl;
    return 0;
}

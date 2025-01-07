#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class MyStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newnode = new Node(val);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }

    void pop()
    {
        if (sz == 0)
            return;
        sz--;
        Node *deletenode = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }
        delete deletenode;
    }

    int top()
    {
        return tail->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        return head == NULL;
    }
};

// Function to check if two stacks are equal
bool areStacksEqual(MyStack &stack1, MyStack &stack2)
{
    // Compare sizes
    if (stack1.size() != stack2.size())
    {
        return false;
    }

    // Compare elements
    while (!stack1.empty() && !stack2.empty())
    {
        if (stack1.top() != stack2.top())
        {
            return false;
        }
        stack1.pop();
        stack2.pop();
    }

    return true;
}

int main()
{
    int n, m;

    // Input first stack
    cin >> n;
    MyStack stack1;
    while (n--)
    {
        int val;
        cin >> val;
        stack1.push(val);
    }

    // Input second stack
    cin >> m;
    MyStack stack2;

    while (m--)
    {
        int val;
        cin >> val;
        stack2.push(val);
    }

    // Check if stacks are equal
    if (areStacksEqual(stack1, stack2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

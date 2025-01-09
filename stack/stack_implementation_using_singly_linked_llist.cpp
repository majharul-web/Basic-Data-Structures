#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

class MyStack
{

public:
    Node *head = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    void pop()
    {
        if (head == NULL)
            return;

        sz--;
        Node *deletenode = head;
        head = head->next;
        delete deletenode;
    }

    int top()
    {
        if (head == NULL)
            return -1;
        return head->val;
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

int main()
{
    MyStack st;
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

#include <bits/stdc++.h>
using namespace std;

class D_Node
{
public:
    int val;
    D_Node *prev;
    D_Node *next;

    D_Node(int val)
    {
        this->prev = NULL;
        this->val = val;
        this->next = NULL;
    }
};

class MyStack
{
public:
    D_Node *head = NULL;
    D_Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
        D_Node *newnode = new D_Node(val);
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

        sz--;
        D_Node *deletenode = tail;
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

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

class MyQueue
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
        tail = newnode;
    }

    void pop()
    {

        sz--;
        Node *deletenode = head;
        head = head->next;
        delete deletenode;

        if (head == NULL)
        {
            tail = NULL;
        }
    }

    int front()
    {

        return head->val;
    }

    int back()
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

string isEqualStackAndQueue(MyStack &st, MyQueue &q)
{

    if (st.size() != q.size())
    {
        return "NO";
    }

    while (!st.empty() && !q.empty())
    {
        if (st.top() != q.front())
        {
            return "NO";
        }
        st.pop();
        q.pop();
    }

    return "YES";
}

int main()
{

    int N, M;
    cin >> N >> M;

    MyStack st;

    while (N--)
    {
        int val;
        cin >> val;
        st.push(val);
    }

    MyQueue q;

    while (M--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << isEqualStackAndQueue(st, q) << endl;

    return 0;
}

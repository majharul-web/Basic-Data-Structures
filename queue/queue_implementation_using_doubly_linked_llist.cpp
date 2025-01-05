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
        newnode->prev = tail;
        tail = newnode;
    }

    void pop()
    {

        sz--;
        Node *deletenode = head;
        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }

        delete deletenode;
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return head->val;
    }

    int back()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
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
    MyQueue q;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "front : " << q.front() << endl;
    cout << "back : " << q.back() << endl;
    cout << "size : " << q.size() << endl;
    cout << "empty before pop : " << (q.empty() == 1 ? "true" : "false") << endl;

    cout << "Queue : ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << "empty after pop : " << (q.empty() == 1 ? "true" : "false") << endl;

    return 0;
}

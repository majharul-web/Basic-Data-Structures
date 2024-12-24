#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

void insert_at_tail(Node *&head, Node *&tail, int val)
{
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

bool is_palindrome(Node *head, Node *tail)
{
    while (head != NULL && tail != NULL && head != tail && head->prev != tail)
    {
        if (head->val != tail->val)
        {
            return false; // Not a palindrome
        }
        head = head->next;
        tail = tail->prev;
    }
    return true; // It's a palindrome
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    // Input the linked list
    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    // Check if the list is a palindrome
    if (is_palindrome(head, tail))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
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

void print_forword(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
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

void doubly_linked_list_reversed(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;

    while (i != j && i->prev != j)
    {
        swap(i->val, j->val);
        i = i->next;
        j = j->prev;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while (true)

    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }
    doubly_linked_list_reversed(head, tail);

    print_forword(head);

    return 0;
}
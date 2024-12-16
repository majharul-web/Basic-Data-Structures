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
    tail = newnode;
    // tail = tail->next;
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
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

    print_linked_list(head);

    // Node *head = new Node(10);
    // Node *a = new Node(20);
    // Node *tail = new Node(30);

    // head->next = a;
    // a->next = tail;

    // insert_at_tail(head, tail, 40);
    // insert_at_tail(head, tail, 50);
    // insert_at_tail(head, tail, 60);
    // print_linked_list(head);
    // cout << "print tail " << tail->val << endl;

    return 0;
}
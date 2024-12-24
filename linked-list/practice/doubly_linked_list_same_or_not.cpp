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

bool same_or_not(Node *head_1, Node *head_2)
{
    Node *temp_1 = head_1;
    Node *temp_2 = head_2;

    while (temp_1 != NULL && temp_2 != NULL)
    {
        if (temp_1->val != temp_2->val)
        {
            return false; // Values do not match
        }
        temp_1 = temp_1->next;
        temp_2 = temp_2->next;
    }

    // If one of the lists is not null, they are not the same
    if (temp_1 != NULL || temp_2 != NULL)
    {
        return false;
    }

    return true; // Both lists are identical
}

int main()
{
    Node *head_1 = NULL;
    Node *tail_1 = NULL;

    Node *head_2 = NULL;
    Node *tail_2 = NULL;

    int val;

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head_1, tail_1, val);
    }

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head_2, tail_2, val);
    }

    print_forword(head_1);
    print_forword(head_2);

    if (same_or_not(head_1, head_2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}

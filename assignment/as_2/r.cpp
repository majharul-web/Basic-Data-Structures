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
}

void remove_duplicate_item(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        Node *temp = current;
        while (temp->next != NULL)
        {
            if (temp->next->val == current->val)
            {
                // Duplicate found, remove the node
                Node *duplicateNode = temp->next;
                temp->next = temp->next->next;
                delete duplicateNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        current = current->next;
    }
}

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
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

    remove_duplicate_item(head);

    print_linked_list(head);

    return 0;
}

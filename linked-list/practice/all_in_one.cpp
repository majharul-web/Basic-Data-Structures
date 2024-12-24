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
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_left_to_right(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_right_to_left(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int get_size(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_at_index(Node *&head, Node *&tail, int index, int val)
{
    if (index < 0 || index > get_size(head))
    {
        cout << "Invalid" << endl;
        return;
    }

    Node *newnode = new Node(val);

    if (index == 0) // Insert at head
    {
        if (head == NULL) // Empty list
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    else if (index == get_size(head)) // Insert at tail
    {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
    else // Insert in the middle
    {
        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        if (temp->next != NULL)
        {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
    }

    // Print the list in both directions
    print_left_to_right(head);
    print_right_to_left(tail);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;
        insert_at_index(head, tail, X, V);
    }

    return 0;
}

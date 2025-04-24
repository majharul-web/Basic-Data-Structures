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

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;

    if (tail == NULL)
    {
        tail = newnode;
    }
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
    tail = newnode;
}

int size_of_linked_list(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// 1. Delete at Head
void delete_at_head(Node *&head, Node *&tail)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;

    if (head == NULL)
    {
        tail = NULL;
    }
}

// 2. Delete at Tail
void delete_at_tail(Node *&head, Node *&tail)
{
    if (head == tail)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = NULL;
}

// 3. Delete at Any Position
void delete_at_position(Node *&head, Node *&tail, int index)
{
    if (index == 0)
    {
        delete_at_head(head, tail);
        return;
    }

    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        if (temp->next == NULL)
        {
            return;
        }
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    if (deleteNode == NULL)
    {
        return;
    }

    temp->next = deleteNode->next;

    if (deleteNode == tail)
    {
        tail = temp;
    }

    delete deleteNode;
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

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (X == 0)
        {
            insert_at_head(head, tail, V);
        }
        else if (X == 1)
        {
            insert_at_tail(head, tail, V);
        }
        else if (X == 2)
        {
            if (head == NULL) // Check at main level
            {

                continue;
            }

            if (V == 0)
            {
                delete_at_head(head, tail); // Delete at head
            }
            else if (V == size_of_linked_list(head) - 1)
            {
                delete_at_tail(head, tail); // Delete at tail
            }
            else
            {
                delete_at_position(head, tail, V); // Delete at position
            }
        }

        print_linked_list(head);
    }

    return 0;
}

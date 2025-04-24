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
void delete_at_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_at_any_position(Node *&head, int index)
{

    Node *temp = head;

    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}

void delete_at_tail(Node *&head, Node *&tail, int index)
{

    Node *temp = head;

    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    Node *deleteNode = temp->next;
    temp->next = temp->next->next;

    delete deleteNode;
    tail = temp;
}

void delete_at_index(Node *&head, Node *&tail, int index)
{
    if (size_of_linked_list(head) == 0 || size_of_linked_list(head) < index)
        return;

    if (index == 0)
    {
        delete_at_head(head);
        return;
    }
    if (index == (size_of_linked_list(head) - 1))
    {
        delete_at_tail(head, tail, index);
        return;
    }
    else
    {
        delete_at_any_position(head, index);
        return;
    }

    // Node *temp = head;
    // for (int i = 1; i < index; i++)
    // {
    //     if (temp->next == NULL)
    //         return; // Invalid index
    //     temp = temp->next;
    // }

    // Node *deleteNode = temp->next;
    // if (deleteNode == NULL)
    //     return; // Invalid index

    // temp->next = deleteNode->next;
    // if (deleteNode == tail)
    // { // Update tail if last node is deleted
    //     tail = temp;
    // }
    // delete deleteNode;
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
            delete_at_index(head, tail, V);
        }

        print_linked_list(head);
    }

    return 0;
}

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
void delete_at_any_position(Node *head, int index)
{

    Node *temp = head;
    for (int i = 1; i < index; i++)
    {
        temp = temp->next;
    }

    Node *deletenode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete deletenode;
}

int main()
{

    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;

    delete_at_any_position(head, 1);

    cout << "printing forword" << endl;
    print_forword(head);

    return 0;
}
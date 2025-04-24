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
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

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

void delete_at_any_index_V(Node *&head, Node *&tail, int index)
{
    int size = size_of_linked_list(head); // 1. Get the size of the linked list
    if (index >= size || size == 0)       // 2. Check if the index is out of bounds or if the list is empty
    {
        return; // If invalid, return without making any changes
    }

    if (index == 0) // 3. If the index is 0, delete the head node
    {
        delete_at_head(head, tail);
        return; // After deleting, we return
    }

    Node *temp = head;                                    // 4. Start traversing from the head
    for (int i = 1; i < index && temp->next != NULL; i++) // 5. Traverse to the node just before the one to be deleted
    {
        temp = temp->next; // Move to the next node
    }

    Node *deleteNode = temp->next; // 6. The node to delete is the one after `temp`
    temp->next = temp->next->next; // 7. Skip the node to delete, making `temp->next` point to the next of the node to be deleted

    if (temp->next == NULL) // 8. If the deleted node was the last node, update the tail
    {
        tail = temp; // Set the tail to the new last node (which is `temp` after the deletion)
    }

    delete deleteNode; // 9. Delete the node (free memory)
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
            delete_at_any_index_V(head, tail, V);
        }

        print_linked_list(head);
    }

    return 0;
}

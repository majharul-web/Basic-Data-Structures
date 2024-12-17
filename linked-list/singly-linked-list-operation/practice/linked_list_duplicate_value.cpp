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

bool contains_duplicate(Node *head)
{
    bool visited[101] = {false}; // Array to track seen values, size 101 (0 to 100)

    Node *temp = head;

    while (temp != NULL)
    {
        if (visited[temp->val]) // If value already exists, duplicate found
        {
            return true;
        }

        visited[temp->val] = true; // Mark the value as seen
        temp = temp->next;         // Move to the next node
    }

    return false; // No duplicates found
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while (true)
    {
        cin >> val;
        if (val == -1) // Stop input when -1 is encountered
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    if (contains_duplicate(head))
    {
        cout << "YES" << endl; // Duplicate found
    }
    else
    {
        cout << "NO" << endl; // No duplicates found
    }

    return 0;
}

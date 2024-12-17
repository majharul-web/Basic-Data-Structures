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

void print_middle(Node *head)
{
    Node *slow = head;      // Slow pointer
    Node *fast = head;      // Fast pointer
    Node *prev_slow = NULL; // To track the previous node of 'slow'

    while (fast != NULL && fast->next != NULL)
    {
        prev_slow = slow;        // Keep track of the previous slow pointer
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }

    // Check for even or odd list length
    if (fast == NULL)
    {
        // Even length: Print the previous slow node and the current slow node
        cout << prev_slow->val << " " << slow->val << endl;
    }
    else
    {
        // Odd length: Print the current slow node
        cout << slow->val << endl;
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

    print_middle(head);

    return 0;
}

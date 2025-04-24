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

int get_diff(Node *head)
{

    int max_val = INT_MIN;
    int min_val = INT_MAX;

    Node *temp = head;
    while (temp != NULL)
    {

        if (temp->val > max_val)
        {
            max_val = temp->val;
        }

        if (temp->val < min_val)
        {
            min_val = temp->val;
        }

        temp = temp->next;
    }

    return max_val - min_val;
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

    int result = get_diff(head);
    cout << result << endl;

    return 0;
}

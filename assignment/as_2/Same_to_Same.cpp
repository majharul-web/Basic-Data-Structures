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

int are_both_linked_lists_is_equal(Node *head_1, Node *head_2)

{
    if (size_of_linked_list(head_1) != size_of_linked_list(head_2))
    {
        return 0;
    }
    else
    {
        Node *temp1 = head_1;
        Node *temp2 = head_2;

        while (temp1 != NULL && temp2 != NULL)
        {

            if (temp1->val != temp2->val)
            {
                return 0;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return 1;
    }
}

int main()
{

    Node *head_1 = NULL;
    Node *tail_1 = NULL;
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

    Node *head_2 = NULL;
    Node *tail_2 = NULL;

    while (true)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }

        insert_at_tail(head_2, tail_2, val);
    }

    if (are_both_linked_lists_is_equal(head_1, head_2) == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

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

int main()
{

    /*
    //static memory allocation

     Node a(10), b(20), c(30);

     a.next = &b;
     b.next = &c;

     cout << a.val << endl;
     cout << a.next->val << endl;
     cout << a.next->next->val << endl;

    */
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    // (*head).next = a;
    head->next = a;
    a->next = b;

    cout << head->val << endl;
    cout << head->next->val << endl;
    cout << head->next->next->val << endl;

    return 0;
}
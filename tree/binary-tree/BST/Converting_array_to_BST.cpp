#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->val << " ";
        if (curr->left != NULL)
        {
            q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            q.push(curr->right);
        }
    }
}

Node *convertAToB(int a[], int n, int l, int r)
{
    if (l > r)
    {
        return NULL;
    }
    int mid = (l + r) / 2;
    Node *root = new Node(a[mid]);
    Node *leftSubtree = convertAToB(a, n, l, mid - 1);
    Node *rightSubtree = convertAToB(a, n, mid + 1, r);

    root->left = leftSubtree;
    root->right = rightSubtree;
    return root;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    Node *root = convertAToB(a, n, 0, n - 1);

    cout << "Printing tree:" << endl;
    levelorder(root);

    return 0;
}
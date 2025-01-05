#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    list<int> l;

    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        l.pop_front();
    }

    int front()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return l.front();
    }

    int back()
    {
        if (empty())
        {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return l.back();
    }

    int size()
    {
        return l.size();
    }

    bool empty()
    {
        return l.empty();
    }
};

int main()
{
    MyQueue q;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int val;
        cin >> val;
        q.push(val);
    }

    cout << "front : " << q.front() << endl;
    cout << "back : " << q.back() << endl;
    cout << "size : " << q.size() << endl;
    cout << "empty before pop : " << (q.empty() == 1 ? "true" : "false") << endl;

    cout << "Queue : ";

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
    cout << "empty after pop : " << (q.empty() == 1 ? "true" : "false") << endl;

    return 0;
}

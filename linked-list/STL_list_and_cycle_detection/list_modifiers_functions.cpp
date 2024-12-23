#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> l1 = {1, 2, 3, 4, 5, 6, 20, 3, 4, 20, 20};
    list<int> l2;
    list<int> l3 = {7, 8, 9};
    vector<int> v = {1, 20, 3, 4, 20, 20, 5, 6};
    // l2 = l1;
    l2.assign(l1.begin(), l1.end());
    l2.push_back(7);
    l2.push_front(0);
    l2.pop_back();
    l2.pop_front();

    // l2.insert(next(l2.begin(), 2), 100);
    // l2.insert(next(l2.begin(), 2), l3.begin(), l3.end());
    // l2.insert(next(l2.begin(), 2), v.begin(), v.end());

    // l2.erase(next(l2.begin(), 3)); //delete single element
    // l2.erase(next(l2.begin(), 2), next(l2.begin(), 4));
    // delete multiple:delete befor end position

    // replace(l2.begin(), l2.end(), 20, 200);

    auto it = find(l2.begin(), l2.end(), 20);

    if (it == l2.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found" << endl;
        cout << *it << endl;
    }

    for (int val : l2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
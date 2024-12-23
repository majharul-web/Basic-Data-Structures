#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> l1;
    cout << "print l1 l1 max size : " << l1.max_size() << endl;

    list<int> l2(10);
    cout << "print l2 size : " << l2.size() << endl;

    vector<int> v = {1, 2, 3, 4, 5, 6};

    list<int> l3(v.begin(), v.end());

    // l3.clear();

    if (l3.empty())
    {
        cout << "Empty l3" << endl;
        return 0;
    }
    // l3.resize(3);
    // l3.resize(10);
    l3.resize(10, 100);

    cout << "printing l3 value using range based for loop : " << endl;
    for (int val : l3)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
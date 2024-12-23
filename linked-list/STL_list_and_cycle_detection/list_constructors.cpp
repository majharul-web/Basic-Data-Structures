#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> l1;
    cout << "print l1 l2 size : " << l1.size() << endl;

    list<int> l2(10);
    cout << "print l2 size : " << l2.size() << endl;

    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> v = {1, 2, 3, 4, 5, 6};
    list<int> temp = {4, 5, 9};

    // list<int> l3(10, 5);
    // list<int> l3 = {1, 2, 3, 4, 5};
    // list<int> l3(temp);
    // list<int>l3(arr, arr + 6);
    list<int> l3(v.begin(), v.end());
    cout << "printing l3 value using for loop : " << endl;
    for (auto it = l3.begin(); it != l3.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "printing l3 value using range based for loop : " << endl;
    for (int val : l3)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
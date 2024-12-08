#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 5, 6, 9, 7, 52, 3};
    vector<int> v2 = {100, 200};

    // assign vector
    /*
    vector<int> v2;
    v2 = v;
    */

    // insert element into last
    // v.push_back(25);

    // delete element from last
    // v.pop_back();

    // insert into vector :v.insert(position,value)
    // v.insert(v.begin() + 2, 100);
    // v.insert(v.begin() + 2, v2.begin(), v2.end());

    // delete from vector:v.erase(position)
    // v.erase(v.begin() + 2);
    v.erase(v.begin() + 2, v.begin() + 4);

    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}
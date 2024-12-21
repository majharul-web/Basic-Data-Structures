#include <bits/stdc++.h>
using namespace std;

int main()
{

    // sequential memory allocation like 72 ,76 ,80 for int value

    int a[5] = {1, 2, 3, 4, 5};
    vector<int> v = {1, 2, 3, 4, 5};

    cout << (uintptr_t)&a[3] << endl;
    cout << (uintptr_t)&a[4] << endl;

    cout << (uintptr_t)&v[3] << endl;
    cout << (uintptr_t)&v[4] << endl;

    return 0;
}
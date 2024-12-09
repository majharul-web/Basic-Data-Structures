#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> v3 = {1, 2, 5, 6, 9, 2, 6, 2};

    cout << "print value using index[i] : " << v3[2] << endl;
    cout << "print value using at(i) : " << v3.at(2) << endl;
    cout << "print last value using size() - 1 : " << v3.size() - 1 << endl;
    cout << "print last value using back() : " << v3.back() << endl;
    cout << "print first value using front() : " << v3.front() << endl;
    cout << "print first value using v3[0] : " << v3[0] << endl;

    return 0;
}
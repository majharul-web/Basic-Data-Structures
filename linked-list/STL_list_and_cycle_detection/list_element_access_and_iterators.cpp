#include <bits/stdc++.h>
using namespace std;

int main()
{

    list<int> l = {1, 2, 6, 8, 7, 9};
    cout << "print first item using *l.begin() iterator : " << *l.begin() << endl;
    // cout << "print last item using *l.end() iterator : " << *l.end() << endl;
    cout << "print first item using l.front() : " << l.front() << endl;
    cout << "print last item using l.back() : " << l.back() << endl;
    cout << "print index item using *next(l.begin(), 2) : " << *next(l.begin(), 2) << endl;

    return 0;
}
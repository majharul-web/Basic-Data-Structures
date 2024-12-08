#include <bits/stdc++.h>
using namespace std;

/*
#There are mainly three asymptotic notations:

1.Big-O Notation (O-notation) ->Best case(found item in first place)
2.Omega Notation (Ω-notation) ->Average case(found item in middle place)
3.Theta Notation (Θ-notation) ->Wrost case(found item in last place)

*/

/*
#rules for calculating time complexity

1.Always take the wrost case
2.Ignore the constant

*/

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i += 2)
    {
        cout << i << " ";
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }

    /*
    #How to understand is it linear complexity

    1.this code complexity == Order of N O(N)
    2.order of operation diff is not big in every loop
    3.loop increment/decrement part using + or -
    */

    return 0;
}
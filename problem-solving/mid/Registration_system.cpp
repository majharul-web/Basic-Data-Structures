#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> userNames;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string userName;
        cin >> userName;
        if (userNames[userName] == 0)
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << userName << userNames[userName] << endl;
        }
        userNames[userName]++;
    }

    return 0;
}
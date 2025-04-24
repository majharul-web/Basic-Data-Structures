#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string s;
        getline(cin, s);
        stringstream ss(s);

        map<string, int> mp;

        string word;
        string mostword = "";
        int maxcount = 0;

        while (ss >> word)
        {

            mp[word]++;

            if (mp[word] > maxcount || (mp[word] == maxcount && mostword == word))
            {
                mostword = word;
                maxcount = mp[word];
            }
        }

        cout << mostword << " " << maxcount << endl;
    }

    return 0;
}

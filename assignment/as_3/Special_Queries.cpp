#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Q;
    cin >> Q;

    queue<string> ticketQ;

    while (Q--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            string name;
            cin >> name;
            ticketQ.push(name);
        }
        else if (command == 1)
        {
            if (!ticketQ.empty())
            {
                cout << ticketQ.front() << endl;
                ticketQ.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}

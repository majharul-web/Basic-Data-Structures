#include <bits/stdc++.h>
using namespace std;

// Function to display the map
void displayMap(const map<string, int> &mp, const string &title)
{
    cout << title << ":\n";
    for (const auto &pair : mp)
    {
        cout << pair.first << " -> " << pair.second << endl;
    }
}

int main()
{
    map<string, int> mp; // Declare a map to store key-value pairs
    int choice;
    string key;
    int value;

    cout << "Interactive Demo of std::map\n";
    cout << "===================================\n";

    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Insert a key-value pair\n";
        cout << "2. Access a value by key\n";
        cout << "3. Check if a key exists\n";
        cout << "4. Modify the value of a key\n";
        cout << "5. Remove a key-value pair\n";
        cout << "6. Display all key-value pairs\n";
        cout << "7. Find the size of the map\n";
        cout << "8. Clear the map\n";
        cout << "9. Exit\n";

        cin >> choice;

        switch (choice)
        {
        case 1: // Insert
            cout << "Enter the key (string): ";
            cin >> key;
            cout << "Enter the value (int): ";
            cin >> value;
            mp[key] = value; // Insert or overwrite
            cout << "Inserted: " << key << " -> " << value << endl;
            break;

        case 2: // Access
            cout << "Enter the key to access: ";
            cin >> key;
            if (mp.find(key) != mp.end())
            {
                cout << "Value: " << mp[key] << endl;
            }
            else
            {
                cout << "Key not found!\n";
            }
            break;

        case 3: // Check existence
            cout << "Enter the key to check: ";
            cin >> key;
            if (mp.count(key))
            {
                cout << "Key exists.\n";
            }
            else
            {
                cout << "Key does not exist.\n";
            }
            break;

        case 4: // Modify
            cout << "Enter the key to modify: ";
            cin >> key;
            if (mp.find(key) != mp.end())
            {
                cout << "Enter the new value: ";
                cin >> value;
                mp[key] = value;
                cout << "Modified: " << key << " -> " << value << endl;
            }
            else
            {
                cout << "Key not found!\n";
            }
            break;

        case 5: // Remove
            cout << "Enter the key to remove: ";
            cin >> key;
            if (mp.erase(key))
            {
                cout << "Key removed.\n";
            }
            else
            {
                cout << "Key not found!\n";
            }
            break;

        case 6: // Display
            displayMap(mp, "Current Map");
            break;

        case 7: // Size
            cout << "The size of the map is: " << mp.size() << endl;
            break;

        case 8: // Clear
            mp.clear();
            cout << "Map cleared.\n";
            break;

        case 9: // Exit
            cout << "Exiting the program. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

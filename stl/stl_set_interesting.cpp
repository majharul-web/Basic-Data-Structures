#include <bits/stdc++.h>
using namespace std;

// Function to display the elements of a set
void displaySet(const set<int> &s, const string &title)
{
    cout << title << ": { ";
    for (const auto &elem : s)
    {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

int main()
{
    set<int> s; // Declare a set to store integers
    int choice, value;

    cout << "Interactive Demo of std::set\n";
    cout << "===================================\n";

    while (true)
    {
        cout << "\nChoose an option:\n";
        cout << "1. Insert an element\n";
        cout << "2. Remove an element\n";
        cout << "3. Check if an element exists\n";
        cout << "4. Display all elements\n";
        cout << "5. Find the size of the set\n";
        cout << "6. Clear the set\n";
        cout << "7. Perform set union with another set\n";
        cout << "8. Perform set intersection with another set\n";
        cout << "9. Exit\n";

        cin >> choice;

        switch (choice)
        {
        case 1: // Insert
            cout << "Enter the element to insert: ";
            cin >> value;
            s.insert(value);
            cout << value << " inserted.\n";
            break;

        case 2: // Remove
            cout << "Enter the element to remove: ";
            cin >> value;
            if (s.erase(value))
            {
                cout << value << " removed.\n";
            }
            else
            {
                cout << value << " not found in the set.\n";
            }
            break;

        case 3: // Find
            cout << "Enter the element to check: ";
            cin >> value;
            if (s.find(value) != s.end())
            {
                cout << value << " exists in the set.\n";
            }
            else
            {
                cout << value << " does not exist in the set.\n";
            }
            break;

        case 4: // Display
            displaySet(s, "Current Set");
            break;

        case 5: // Size
            cout << "The size of the set is: " << s.size() << endl;
            break;

        case 6: // Clear
            s.clear();
            cout << "Set cleared.\n";
            break;

        case 7:
        { // Union
            set<int> anotherSet;
            int n, elem;
            cout << "Enter the number of elements for the second set: ";
            cin >> n;
            cout << "Enter the elements for the second set:\n";
            while (n--)
            {
                cin >> elem;
                anotherSet.insert(elem);
            }

            set<int> resultSet = s;                                 // Start with the first set
            resultSet.insert(anotherSet.begin(), anotherSet.end()); // Union

            displaySet(s, "First Set");
            displaySet(anotherSet, "Second Set");
            displaySet(resultSet, "Union of Sets");
            break;
        }

        case 8:
        { // Intersection
            set<int> anotherSet;
            int n, elem;
            cout << "Enter the number of elements for the second set: ";
            cin >> n;
            cout << "Enter the elements for the second set:\n";
            while (n--)
            {
                cin >> elem;
                anotherSet.insert(elem);
            }

            set<int> resultSet; // For the intersection
            for (const auto &elem : s)
            {
                if (anotherSet.find(elem) != anotherSet.end())
                {
                    resultSet.insert(elem); // Common elements
                }
            }

            displaySet(s, "First Set");
            displaySet(anotherSet, "Second Set");
            displaySet(resultSet, "Intersection of Sets");
            break;
        }

        case 9: // Exit
            cout << "Exiting the program. Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

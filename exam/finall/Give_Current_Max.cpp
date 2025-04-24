#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int age;
    int marks;

    Student(string name, int age, int marks)
    {
        this->name = name;
        this->age = age;
        this->marks = marks;
    }
};

// Custom comparator
class CustomCompare
{
public:
    bool operator()(const Student &s1, const Student &s2)
    {
        if (s1.marks == s2.marks)
        {
            return s1.age > s2.age;
        }
        return s1.marks < s2.marks;
    }
};

int main()
{
    int N, Q;
    cin >> N;

    priority_queue<Student, vector<Student>, CustomCompare> A;

    for (int i = 0; i < N; i++)
    {
        string name;
        int age, marks;
        cin >> name >> age >> marks;
        A.push(Student(name, age, marks));
    }

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int command;
        cin >> command;

        switch (command)
        {
        case 0:
        {
            string name;
            int age, marks;
            cin >> name >> age >> marks;
            A.push(Student(name, age, marks));

            cout << A.top().name << " " << A.top().age << " " << A.top().marks << endl;

            break;
        }
        case 1:
            if (A.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << A.top().name << " " << A.top().age << " " << A.top().marks << endl;
            }
            break;

        case 2:
            if (A.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                A.pop();
                if (A.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    cout << A.top().name << " " << A.top().age << " " << A.top().marks << endl;
                }
            }
            break;

        default:
            cout << "Invalid Command" << endl;
            break;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

// Custom comparator for the priority queue
class CompareMarks
{
public:
    bool operator()(const Student s1, const Student s2)
    {
        // Higher marks have higher priority; if marks are equal, lower roll has higher priority
        if (s1.marks == s2.marks)
            return s1.roll > s2.roll; // Compare by roll number

        return s1.marks < s2.marks; // Compare by marks
    }
};

int main()
{
    // Priority queue with custom comparator
    priority_queue<Student, vector<Student>, CompareMarks> studentPQ;

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    // Input student details
    cout << "Enter student details (name, roll, marks):\n";
    for (int i = 0; i < n; ++i)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        studentPQ.push(Student(name, roll, marks));
    }

    cout << "Student with the highest marks: "
         << studentPQ.top().name << " (Roll: " << studentPQ.top().roll
         << ", Marks: " << studentPQ.top().marks << ")\n";

    cout << "Removing students from the queue based on their priority...\n";
    while (!studentPQ.empty())
    {
        Student topStudent = studentPQ.top();
        cout << "Student: " << topStudent.name
             << " (Roll: " << topStudent.roll
             << ", Marks: " << topStudent.marks << ")\n";
        studentPQ.pop();
    }

    return 0;
}

/*

input:

Alice 101 85
Bob 102 92
Charlie 103 85
Diana 104 92
Eve 105 78

*/
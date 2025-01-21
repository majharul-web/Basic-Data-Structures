#include <bits/stdc++.h>
using namespace std;

int main()
{

    priority_queue<int> taskManager;

    cout << "Task Manager(Max-Heap) Simulation\n";
    cout << "------------------------\n";

    // Adding tasks with different priorities
    cout << "Adding tasks with priorities 10, 20, 5, and 30...\n";
    taskManager.push(10);
    taskManager.push(20);
    taskManager.push(5);
    taskManager.push(30);

    // Display the current highest-priority task
    cout << "Current top priority task: " << taskManager.top() << "\n";

    // Removing the top-priority task
    cout << "Completing the top priority task (" << taskManager.top() << ")...\n";
    taskManager.pop();

    // Display the new top-priority task
    cout << "New top priority task: " << taskManager.top() << "\n";

    // Adding another task
    cout << "Adding a new task with priority 25...\n";
    taskManager.push(25);

    // Display the updated top-priority task
    cout << "Updated top priority task: " << taskManager.top() << "\n";

    // Displaying the size of the task manager
    cout << "Total tasks in the manager: " << taskManager.size() << "\n";

    // Completing all remaining tasks
    cout << "Completing all tasks...\n";
    while (!taskManager.empty())
    {
        cout << "Completing task with priority: " << taskManager.top() << "\n";
        taskManager.pop();
    }

    // Checking if the task manager is empty
    cout << "All tasks completed. Task manager empty: " << (taskManager.empty() ? "Yes" : "No") << "\n";

    return 0;
}

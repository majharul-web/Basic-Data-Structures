#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Min-heap using a priority queue with std::greater<int>
    priority_queue<int, vector<int>, greater<int>> minHeap;

    cout << "Task Scheduler (Min-Heap) Simulation\n";
    cout << "-------------------------------------\n";

    // Adding tasks with different priorities (lower numbers = higher priority)
    cout << "Adding tasks with priorities 50, 10, 30, 20...\n";
    minHeap.push(50); // Adding a task with priority 50
    minHeap.push(10); // Adding a task with priority 10
    minHeap.push(30); // Adding a task with priority 30
    minHeap.push(20); // Adding a task with priority 20

    // Display the current highest-priority task
    cout << "Task with the highest priority: " << minHeap.top() << "\n";

    // Removing the top-priority task
    cout << "Completing the highest priority task (" << minHeap.top() << ")...\n";
    minHeap.pop();

    // Display the new top-priority task
    cout << "New highest priority task: " << minHeap.top() << "\n";

    // Adding another task
    cout << "Adding a new task with priority 15...\n";
    minHeap.push(15);

    // Display the updated top-priority task
    cout << "Updated highest priority task: " << minHeap.top() << "\n";

    // Displaying the size of the min-heap
    cout << "Total tasks in the scheduler: " << minHeap.size() << "\n";

    // Completing all remaining tasks
    cout << "Completing all tasks...\n";
    while (!minHeap.empty())
    {
        cout << "Completing task with priority: " << minHeap.top() << "\n";
        minHeap.pop();
    }

    // Checking if the min-heap is empty
    cout << "All tasks completed. Task scheduler empty: " << (minHeap.empty() ? "Yes" : "No") << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int val)
{
    v.push_back(val);
    int curr_idx = v.size() - 1;

    while (curr_idx != 0)
    {
        int par_idx = (curr_idx - 1) / 2;
        if (v[par_idx] > v[curr_idx]) // Min-heap condition
        {
            swap(v[par_idx], v[curr_idx]);
        }
        else
        {
            break;
        }
        curr_idx = par_idx;
    }
}

void print_heap(const vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void delete_heap(vector<int> &v)
{
    if (v.empty())
    {
        cout << "Heap is empty!" << endl;
        return;
    }

    // Replace the root with the last element and remove the last element
    v[0] = v.back();
    v.pop_back();

    int curr_idx = 0;
    int n = v.size();

    // "Heapify down" to restore the min-heap property
    while (true)
    {
        int left = 2 * curr_idx + 1;  // Left child index
        int right = 2 * curr_idx + 2; // Right child index
        int smallest = curr_idx;

        // Check if left child is smaller
        if (left < n && v[left] < v[smallest])
        {
            smallest = left;
        }

        // Check if right child is smaller
        if (right < n && v[right] < v[smallest])
        {
            smallest = right;
        }

        // If the smallest is not the current index, swap and continue heapifying down
        if (smallest != curr_idx)
        {
            swap(v[curr_idx], v[smallest]);
            curr_idx = smallest;
        }
        else
        {
            break; // Min-heap property is restored
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insert_heap(v, val);
    }

    cout << "Heap after insertion: ";
    print_heap(v);

    delete_heap(v);

    cout << "Heap after deletion: ";
    print_heap(v);

    return 0;
}

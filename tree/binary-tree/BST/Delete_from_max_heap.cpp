#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int val)
{
    v.push_back(val);
    int curr_idx = v.size() - 1;

    while (curr_idx != 0)
    {
        int par_idx = (curr_idx - 1) / 2;
        if (v[par_idx] < v[curr_idx]) // Max-heap condition
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

    v[0] = v.back();
    v.pop_back();

    int curr_idx = 0;
    int n = v.size();

    while (true)
    {
        int left = 2 * curr_idx + 1;
        int right = 2 * curr_idx + 2;
        int largest = curr_idx;

        if (left < n && v[left] > v[largest])
        {
            largest = left;
        }
        if (right < n && v[right] > v[largest])
        {
            largest = right;
        }

        if (largest != curr_idx)
        {
            swap(v[curr_idx], v[largest]);
            curr_idx = largest;
        }
        else
        {
            break;
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

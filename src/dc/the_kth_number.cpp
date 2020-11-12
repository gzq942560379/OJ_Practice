#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <iterator>

using namespace std;

int the_kth_number_sort(vector<int> &vec, int k)
{
    sort(vec.begin(), vec.end());
    return vec[vec.size() - k];
}

int the_kth_number_heap(vector<int> &vec, int k)
{
    make_heap(vec.begin(), vec.end());
    while (k > 1)
    {
        pop_heap(vec.begin(), vec.end());
        vec.pop_back();
        k -= 1;
    }
    pop_heap(vec.begin(), vec.end());
    return vec.back();
}

int the_kth_number_queue(vector<int> &vec, int k)
{
    priority_queue<int> q;
    for (auto i : vec)
    {
        q.push(i);
    }
    while (k > 1)
    {
        q.pop();
        k -= 1;
    }
    return q.top();
}

int partition(vector<int> &vec, int left, int right)
{
    int pivot = vec[left];
    int i = left;
    int j = right;
    while (i < j)
    {
        for (i = i + 1; i < right && vec[i] <= pivot; ++i)
            ;
        for (j = j - 1; j >= left && vec[j] > pivot; --j)
            ;
        if (i < j)
            swap(vec[i], vec[j]);
    }
    vec[left] = vec[j];
    vec[j] = pivot;
    return j;
}

int the_kth_number_partition_select(vector<int> &vec, int k)
{
    int left = 0;
    int right = vec.size();
    int target = vec.size() - k;
    while (true)
    {
        int mid = partition(vec, left, right);
        if (target == mid)
            return vec[target];
        else if (target < mid)
            right = mid;
        else if (target > mid)
            left = mid + 1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int size, k;
    cin >> size >> k;
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
    cout << the_kth_number_queue(vec, k);
}
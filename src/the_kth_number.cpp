#include <algorithm>
#include <vector>
#include <iostream>

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

int main()
{
    int size, k;
    cin >> size >> k;
    vector<int> vec(size);
    for (int i = 0; i < size; i++)
    {
        cin >> vec[i];
    }
    cout << the_kth_number_heap(vec, k);
}
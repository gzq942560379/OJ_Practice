#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int count_inversion_naive(vector<int> &vec)
{
    int m = vec.size();
    int counter = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (vec[i] > 3 * vec[j])
            {
                counter++;
            }
        }
    }
    return counter;
}

int merge_count(vector<int> &vec, int left, int mid, int right)
{
    int count = 0;
    //count
    int i = mid - 1, j = right - 1;
    while (i >= left && j >= mid)
    {
        if (vec[i] > (long long)vec[j] * 3)
        {
            count += j - mid + 1;
            i--;
        }
        else
        {
            j--;
        }
    }

    //merge
    i = left;
    j = mid;
    int k = 0;
    vector<int> tmp(right - left);
    while (i < mid && j < right)
    {
        if (vec[i] <= vec[j])
        {
            tmp[k++] = vec[i++];
        }
        else
        {
            tmp[k++] = vec[j++];
        }
    }
    while (i < mid)
    {
        tmp[k++] = vec[i++];
    }
    while (j < right)
    {
        tmp[k++] = vec[j++];
    }
    copy(tmp.begin(), tmp.end(), next(vec.begin(), left));
    return count;
}

int sort_count(vector<int> &vec, int left, int right)
{
    if (right - left == 1)
    {
        return 0;
    }
    else
    {
        int mid = (left + right) >> 1;
        int cl = sort_count(vec, left, mid);
        int cr = sort_count(vec, mid, right);
        int cm = merge_count(vec, left, mid, right);
        return cl + cr + cm;
    }
}

int count_inversion_merge(vector<int> &vec)
{
    return sort_count(vec, 0, vec.size());
}

int main()
{
    ios::sync_with_stdio(false);
    int m;
    cin >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }
    cout << count_inversion_merge(vec);
}
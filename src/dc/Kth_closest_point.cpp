#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct
{
    long long x;
    long long y;
    long long distance;
} point_t;

point_t select_by_sort(vector<point_t> &vec, int left, int right, int target)
{

    sort(next(vec.begin(), left), next(vec.begin(), right), [](const point_t &a, const point_t &b) -> bool { return a.distance < b.distance; });
    return vec[target];
}

// partition 2 分区 [left, j - 1] [j] [j+1, right]
point_t select_two_region(vector<point_t> &vec, int left, int right, int target)
{
    swap(vec[left], vec[(left + right) >> 1]);
    point_t pivot = vec[left];
    long long pivotVal = pivot.distance;
    int i = left;
    int j = right;
    while (i < j)
    {
        for (i = i + 1; i < right && vec[i].distance <= pivotVal; ++i)
            ;
        for (j = j - 1; j >= left && vec[j].distance > pivotVal; --j)
            ;
        if (i < j)
            swap(vec[i], vec[j]);
    }
    swap(vec[left], vec[j]);

    if (target < j)
        return select_two_region(vec, left, j, target);
    else if (target > j)
        return select_two_region(vec, j + 1, right, target);
    else
        return vec[target];
}

// partition 3 分区 [left , l) [l , r] [r + 1, right)
point_t select_three_region(vector<point_t> &vec, int left, int right, int target)
{
    swap(vec[left], vec[(left + right) >> 1]);
    point_t pivot = vec[left];
    long long pivotVal = pivot.distance;
    int l = left, i = left + 1, r = right - 1;
    while (i <= r)
    {
        if (vec[i].distance < pivotVal)
            swap(vec[l++], vec[i++]);
        else if (vec[i].distance > pivotVal)
            swap(vec[r--], vec[i]);
        else
            i++;
    }
    if (target < l)
        return select_three_region(vec, left, l, target);
    else if (target > r)
        return select_three_region(vec, r + 1, right, target);
    else
        return vec[target];
}

int main()
{
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    long long tmp_x, tmp_y;
    vector<point_t> vec(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> tmp_x >> tmp_y;
        vec[i] = {tmp_x, tmp_y, tmp_x * tmp_x + tmp_y * tmp_y};
    }
    point_t p = select_three_region(vec, 0, N, K - 1);
    cout << p.x << " " << p.y << endl;
}

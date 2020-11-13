#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob_(vector<int> &nums, size_t left, size_t right)
    {
        size_t size = right - left;
        if (size == 1)
            return nums[left];
        vector<int> dp(size);
        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);
        for (size_t i = 2; i < size; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[left + i]);
        }
        return dp[size - 1];
    }

    int rob(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        return max(rob_(nums, 0, nums.size() - 1), rob_(nums, 1, nums.size()));
    }
};

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
    cout << Solution().rob(vec);
}
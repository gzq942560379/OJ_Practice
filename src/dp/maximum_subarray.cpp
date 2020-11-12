#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int ret = 0;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        ret = dp[0];
        for (unsigned long i = 1; i < nums.size(); i++)
        {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ret = max(ret, dp[i]);
        }
        return ret;
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
    cout << Solution().maxSubArray(vec);
}

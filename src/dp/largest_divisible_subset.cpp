#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        if (nums.empty())
            return vector<int>();
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size());
        vector<int> pre(nums.size(), -1);
        dp[0] = 1;
        int max_num = 1;
        int max_index = 0;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            dp[i] = 1;
            pre[i] = -1;
            for (size_t j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            if (max_num < dp[i])
            {
                max_num = dp[i];
                max_index = i;
            }
        }
        // 构造输出
        vector<int> ret;
        for (int index = max_index; index != -1; index = pre[index])
        {
            ret.push_back(nums[index]);
        }
        reverse(ret.begin(), ret.end());
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
    vector<int> ret = Solution().largestDivisibleSubset(vec);
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ","));
}

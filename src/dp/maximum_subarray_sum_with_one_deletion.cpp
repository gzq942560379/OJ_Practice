#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp1(nums.size()); // not delete
        vector<int> dp2(nums.size()); // delete once
        dp1[0] = nums[0];
        int ret = dp1[0];
        for (unsigned long i = 1; i < nums.size(); i++)
        {
            dp1[i] = max(nums[i], dp1[i - 1] + nums[i]);
            ret = max(ret, dp1[i]);
        }
        dp2[0] = dp1[0];
        dp2[1] = dp1[1];
        for (unsigned long i = 2; i < nums.size(); i++)
        {
            dp2[i] = max(dp1[i - 2] + nums[i], dp2[i - 1] + nums[i]);
            ret = max(ret, dp2[i]);
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
    cout << Solution().maximumSum(vec);
}

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
        vector<int> opt(nums.size());
        vector<int> pre(nums.size(), -1);
        opt[0] = 1;
        int max_num = 1;
        int max_index = 0;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            opt[i] = 1;
            pre[i] = -1;
            for (size_t j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && opt[j] + 1 > opt[i])
                {
                    opt[i] = opt[j] + 1;
                    pre[i] = j;
                }
            }
            if (max_num < opt[i])
            {
                max_num = opt[i];
                max_index = i;
            }
        }
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

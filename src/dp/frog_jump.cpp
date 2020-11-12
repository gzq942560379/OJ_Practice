#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <list>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        vector<unordered_set<long long>> m(n, unordered_set<long long>());
        m[0].insert(0);
        vector<long long> dp(n, 0);
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            //找到刚好能到达i的石头
            while (dp[k] + 1 < stones[i] - stones[k])
                ++k;
            for (int j = k; j < i; j++)
            {
                long long step = stones[i] - stones[j];
                if (m[j].count(step - 1) || m[j].count(step) || m[j].count(step + 1))
                {
                    m[i].insert(step);
                    dp[i] = max(step, dp[i]);
                }
            }
        }
        return dp.back() > 0;
    }
};

// TLE
class Solution_TLE_2
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones.size() <= 1)
            return true;
        vector<list<int>> dp(stones.size());
        dp[0].push_back(0);
        for (size_t i = 0; i < stones.size(); i++)
        {
            if (!dp[i].empty())
            {
                for (int k : dp[i])
                {
                    for (size_t j = i + 1; j < stones.size(); j++)
                    {
                        int distance = stones[j] - stones[i];
                        if (distance > k + 1)
                            break;
                        if (distance >= k - 1)
                            dp[j].push_back(distance);
                    }
                }
            }
        }
        return !dp[stones.size() - 1].empty();
    }
};

// TLE
class Solution_TLE_1
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones.size() <= 1)
            return true;
        vector<list<int>> dp(stones.size());
        dp[0].push_back(0);
        for (size_t i = 0; i < stones.size(); i++)
        {
            for (size_t j = 0; j < i; ++j)
            {
                if (!dp[j].empty())
                {
                    int distance = stones[i] - stones[j];
                    for (int k : dp[j])
                    {
                        if (distance >= k - 1 && distance <= k + 1)
                        {
                            dp[i].push_back(distance);
                        }
                    }
                }
            }
        }
        return !dp[stones.size() - 1].empty();
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
    cout << Solution().canCross(vec);
}

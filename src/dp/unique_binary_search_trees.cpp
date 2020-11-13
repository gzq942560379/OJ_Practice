#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        if (n < 2)
            return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    cout << Solution().numTrees(n);
}

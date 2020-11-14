#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int money)
    {
        vector<vector<int>> opt(coins.size() + 1, vector<int>(money + 1));
        int MAX = money + 1;
        for (int i = 0; i <= money; ++i)
            opt[0][i] = MAX;
        for (size_t i = 0; i <= coins.size(); ++i)
            opt[i][0] = 0;
        for (int i = 1; i <= money; ++i)
        {
            for (size_t j = 1; j <= coins.size(); ++j)
            {
                if (coins[j - 1] <= i)
                    opt[j][i] = min(opt[j - 1][i], opt[j][i - coins[j - 1]] + 1);
                else
                    opt[j][i] = opt[j - 1][i];
            }
        }
        return opt[coins.size()][money] == MAX ? -1 : opt[coins.size()][money];
    };
};

int main()
{
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }
    cin >> n;
    cout << Solution().coinChange(vec, n);
}

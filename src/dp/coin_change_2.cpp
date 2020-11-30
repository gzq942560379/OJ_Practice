#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int change(int money, vector<int> &coins)
    {
        vector<vector<int>> opt(coins.size() + 1, vector<int>(money + 1));
        for (int i = 0; i <= money; ++i)
            opt[0][i] = 0;
        for (size_t i = 0; i <= coins.size(); ++i)
            opt[i][0] = 1;
        for (int i = 1; i <= money; ++i)
        {
            for (size_t j = 1; j <= coins.size(); ++j)
            {
                if (coins[j - 1] <= i)
                    opt[j][i] = opt[j - 1][i] + opt[j][i - coins[j - 1]];
                else
                    opt[j][i] = opt[j - 1][i];
            }
        }
        return opt[coins.size()][money];
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
    cout << Solution().change(n, vec);
}

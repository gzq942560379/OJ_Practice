#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &money)
    {
        if (money.size() == 0)
            return 0;
        if (money.size() == 1)
            return money[0];
        vector<int> opt(money.size());
        opt[0] = money[0];
        opt[1] = max(money[0], money[1]);
        for (size_t i = 2; i < money.size(); ++i)
            opt[i] = max(opt[i - 1], opt[i - 2] + money[i]);
        return opt[money.size() - 1];
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
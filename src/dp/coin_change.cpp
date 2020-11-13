#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
    }
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

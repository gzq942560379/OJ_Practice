#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob_(vector<int> &money, size_t left, size_t right)
    {
        size_t size = right - left;
        if (size == 1)
            return money[left];
        vector<int> opt(size);
        opt[0] = money[left];
        opt[1] = max(money[left], money[left + 1]);
        for (size_t i = 2; i < size; ++i)
            opt[i] = max(opt[i - 1], opt[i - 2] + money[left + i]);
        return opt[size - 1];
    }
    int rob(vector<int> &money)
    {
        if (money.size() == 0)
            return 0;
        if (money.size() == 1)
            return money[0];
        return max(rob_(money, 0, money.size() - 1), rob_(money, 1, money.size()));
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
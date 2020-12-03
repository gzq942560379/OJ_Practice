#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int numRescueBoats(vector<int> &weight, int limit)
    {
        sort(weight.begin(), weight.end(), std::greater<int>());
        size_t i = 0;
        size_t j = weight.size() - 1;
        int count = 0;
        while (i <= j)
        {
            if (weight[i] + weight[j] <= limit)
                j -= 1;
            i += 1;
            count += 1;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m;
    cin >> n;
    vector<int> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }
    cout << Solution().numRescueBoats(vec, n);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int assignBananaToMonkeys(vector<int> &monkeys, vector<int> &bananas)
{
    sort(monkeys.begin(), monkeys.end());
    sort(bananas.begin(), bananas.end());
    int ret = 0;
    for (size_t i = 0; i < monkeys.size(); ++i)
    {
        ret = max(ret, abs(monkeys[i] - bananas[i]));
    }
    return ret;
}

void inputIntRow(vector<int> &vec)
{
    size_t i = 0;
    int temp;
    while (cin >> temp)
    {
        ++i;
        vec.push_back(temp);
        if (cin.get() == '\n')
            break;
    }
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    vector<int> monkeys;
    vector<int> bananas;
    inputIntRow(monkeys);
    inputIntRow(bananas);
    cout << assignBananaToMonkeys(monkeys, bananas);
    return 0;
}

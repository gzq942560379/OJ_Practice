#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jobSchedule(vector<int> &p, vector<int> &f)
{
    return 0;
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
    vector<int> p;
    vector<int> f;
    inputIntRow(p);
    inputIntRow(f);
    cout << jobSchedule(p, f);
    return 0;
}

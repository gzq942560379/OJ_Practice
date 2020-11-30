#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void triangle(vector<long long> &length)
{
    sort(length.begin(), length.end());
    for (size_t i = 2, ie = length.size(); i < ie; ++i)
    {
        if (length[i - 2] + length[i - 1] > length[i])
        {
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    size_t N;
    cin >> N;
    vector<long long> length(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> length[i];
    }
    triangle(length);
    return 0;
}

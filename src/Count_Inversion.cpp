#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<int> vec(m);
    for (int i = 0; i < m; i++)
    {
        cin >> vec[i];
    }
    int counter = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (vec[i] > 3 * vec[j])
            {
                counter++;
            }
        }
    }
    cout << counter;
}
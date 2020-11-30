#include <iostream>
#include <string>
#include <stack>

using namespace std;

int stringBomb(string &str)
{
    stack<char> s;
    for (char c : str)
    {
        if (c == 'A')
        {
            s.push(c);
        }
        else
        {
            if (!s.empty())
                s.pop();
            else
                s.push(c);
        }
    }
    return s.size();
}

int main(int argc, char const *argv[])
{
    std::ios::sync_with_stdio(false);
    string m;
    cin >> m;
    cout << stringBomb(m);
    return 0;
}

#include <iostream>

using namespace std;

const long long MOD = 1000;

long long f1(long long base, long long power)
{
    if(base == 0 && power != 0){
        return 0;
    }
    base = base < 0 ? -base : base;
    long long result = 1;
    while (power > 0)
    {
        if (power & 1)
        {
            result = result * base % MOD;
        }
        power >>= 1;
        base = (base * base) % MOD;
    }
    return result;
}

int main()
{
    long long base, power;
    cin >> base >> power;
    cout << f1(base, power);
}
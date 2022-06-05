#include <bits/stdc++.h>

using namespace std;

mt19937 r;

long long rr(long long p, long long k)
{
    return r() % (k - p + 1) + p;
}

int main()
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int z = rr(1, 100);
    cout << z << "\n";
    while(z--)
    {
        cout<<rr(1, 1e12) << "\n";
    }
}

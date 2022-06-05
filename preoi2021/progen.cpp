#include <bits/stdc++.h>

using namespace std;

mt19937 r;


int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

int main()
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int n, m, q;
    n = rr(1, 100);
    m = rr(1, 100);
    q= rr(0, n * m);
    cout << n << " " << m << " " << q << "\n";
    while(q--)
        cout << rr(1, n) << " " << rr(1, m) << "\n";
}
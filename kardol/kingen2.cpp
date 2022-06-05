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
    int m = rr(1, 8 * 1000);
    int n = rr(m, 8 * 1000);
    cout << n << " " << m << "\n";
    for(int i = 0; i < n; i++)
        cout << rr(1, m) << " ";
    cout << "\n";
    for(int i = 0; i < m; i++)
        cout << rr(1, 1000 * 1000) << " ";
}
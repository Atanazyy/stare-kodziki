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
    int n = 1;
    int m = rr(1, 1000);
    int k = 1;
    int l = rr(1, m);
    cout << n << " " << m << " " << k << " " << l << "\n";
    for(int i = 1; i <= m; i++)
        cout << rr(1, 1000000) << " ";
}
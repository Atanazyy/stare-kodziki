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
    int n = rr(1, 1000 * 1000);
    int m = rr(n, 1000 * 1000);
    for(int i = 0; i < n; i++)
        cout << (char)rr('a', 'z');
    cout << " ";
    for(int i = 0; i < m; i++)
        cout << (char)rr('a', 'z');
}
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
    int n, m, l , k;
    n = rr(1, 3);
    m = rr(1, 3);
    l = rr(n, 10);
    k = rr(m, 10);
    cout << n << " " << m << "\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << (char)rr('a', 'c');
        }
        cout << "\n";
    }
    cout << l << " " << k << "\n";
    for(int i = 0; i < l; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cout << (char)rr('a', 'c');
        }
        cout << "\n";
    }
}
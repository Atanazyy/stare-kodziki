#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int p, int k)
{
    return p + (r() % (k - p + 1));
}

int main()
{
    int nr;
    cin >> nr;
    r.seed(nr);
    int n, k;
    n = rr(1, 5);
    k = rr(1, 5);
    cout << n << " " << k << "\n";
    for(int i = 0; i < n; i++)
        cout << rr(1, k) << " ";
    cout << "\n";
    for(int i = 1; i < k; i++)
    {
        cout << i << " " << rr(i + 1, k) << "\n";
    }
}

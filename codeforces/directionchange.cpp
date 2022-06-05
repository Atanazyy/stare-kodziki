#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    if(n == m && n == 1)
    {
        cout << "0\n";
        return;
    }
    if(min(n, m) == 1 && max(n, m) == 2)
    {
        cout << "1\n";
        return;
    }
    if(min(n, m) == 1)
    {
        cout << "-1\n";
        return;
    }
    long long nn = min(n, m), nm = max(n, m);
    long long wyn = (nn - 1) * 2;
    long long doz = nm - nn;
    if(doz % 2 == 0)
        cout << (doz * 2) + wyn << "\n";
    else
        cout << (doz * 2 - 1) + wyn << "\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}
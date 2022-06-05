#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long a, b;
    cin >> a >> b;
    if(a % 2 != b % 2)
    {
        cout << "-1\n";
        return;
    }
    if(a == 0 && b == 0)
    {
        cout << "0\n";
        return;
    }
    if(a == b)
    {
        cout << "1\n";
        return;
    }
    cout << "2\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
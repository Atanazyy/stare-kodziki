#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> lu;
    long long zaj = 0;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        lu.push_back(a);
    }
    sort(lu.begin(), lu.end());
    reverse(lu.begin(), lu.end());
    zaj = 2 + 2 * lu[0];
    int wie = lu[0], mie = lu[0];
    for(int i = 1; i < lu.size() - 1; i++)
    {
        zaj += lu[i] + 1;

    }
    //cout << zaj;
    if(zaj <= m)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solve();
}
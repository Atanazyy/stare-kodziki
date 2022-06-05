#include <bits/stdc++.h>

using namespace std;

const int r = 3e5 + 9;

int pre[r];

void solve()
{
    int me, xo;
    cin >> me >> xo;
    int x = pre[me - 1];
    //cout << x << " " << (x ^ xo) << " ";
    if(x == xo)
        cout << me << "\n";
    else if((xo ^ x) == me)
        cout << me + 2 << "\n";
    else 
        cout << me + 1 <<"\n";
}

int main()
{
    for(int i = 1; i < r; i++)
        pre[i] = pre[i - 1] ^ i;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
    
#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
int tab[r];

void solve()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    while(q--)
    {
        int c, x;
        cin >> c >> x;
        if(c == 1)
            tab[x]++;
        if(c == 2)
            tab[x]--;
        if(c == 3)
        {
            double xd = x;
            long long wyn = 0;
            for(int i = 1; i <= n; i++)
            {
                wyn += ceil(tab[i] / xd);
            }
            cout << wyn << "\n";
        }
    }
}

int main()
{
    int z;
    cin >> z;
    while(z--)
    {
        solve();
    }
}

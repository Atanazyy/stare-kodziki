#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
const int inf = 1e9;
int tab[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    int wyn = inf;
    for(int i = 0; i <= 30; i++)
    {
        int ost = -inf, s = 1 << i;
        for(int j = 1; j <= n; j++)
        {
            int x = tab[j] / s;
            if(x % 2 == 1)
            {
                //cout << i << " " << j << "\n";
                wyn = min(wyn, j - ost);
                ost = j;
            }
        }
    }
    if(wyn < inf) cout << wyn;
    else cout << -1;
}
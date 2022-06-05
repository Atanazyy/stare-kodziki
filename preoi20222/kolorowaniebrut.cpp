#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
long long war[r];
int kol[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> war[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> kol[i];
    }
    int q;
    cin >> q;
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int i, x;
            cin >> i >> x;
            war[i] = x;
        }
        if(t == 2)
        {
            int l, r, c;
            cin >> l >> r >> c;
            for(int i = l; i <= r; i++)
            {
                kol[i] = c;
            }
        }
        if(t == 3)
        {
            int c;
            cin >> c;
            long long wyn = 0;
            for(int i = 1; i <= n; i++)
            {
                if(kol[i] == c)
                    wyn += war[i];
            }
            cout << wyn <<"\n";
        }
    }
}

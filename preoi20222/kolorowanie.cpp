#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
long long sum[r];
int kol[r];
long long war[r];

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
        sum[kol[i]] += war[i];
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
            sum[kol[i]] += x - war[i];
            war[i] = x;
        }
        if(t == 2)
        {
            int l, r, c;
            cin >> l >> r >> c;
            for(int i = l; i <= r; i++)
            {
                sum[kol[i]] -= war[i];
                kol[i] = c;
                sum[kol[i]] += war[i];
            }
        }
        if(t == 3)
        {
            int c;
            cin >> c;
            cout << sum[c] << "\n";
        }
    }
}
/*
8
4 1 -2 0 -1 4 3 7
1 2 2 2 3 1 1 3
9
3 1
3 3
2 3 4 1
3 1
3 2
1 6 -3
3 1
2 1 3 3
3 2
*/

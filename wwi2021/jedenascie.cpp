#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

int tab[r][2];
int dp[4 * r];
int dn[4 * r];

void push(int v, int wp, int wn)
{
    while(v > 0)
    {
        dp[v] = (22 + dp[v] + wp)  % 11;
        dn[v] = (22 + dn[v] + wn)  % 11;
        v/=2;
    }
}

pair<int, int> czyt(int a, int b)
{
    if(a == b)
    {
        return {dp[a], dn[a]};
    }
    int wp = (dp[a] + dp[b]) % 11, wn = (dn[a] + dn[b]) % 11;
    while(a / 2 != b / 2)
    {
       // cout<<a<<" "<<b<<", ";
        if(a % 2 == 0)
        {
            wp = (wp + dp[a + 1]) % 11;
            wn = (wn + dn[a + 1]) % 11;
        }
        if(b % 2 == 1)
        {
            wp = (wp + dp[b - 1]) % 11;
            wn = (wn + dn[b - 1]) % 11;
        }
        a/=2;
        b/=2;
    }
    return {wp, wn};
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q, roz;
    cin >> n >> q;
    string s;
    cin>>s;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
    {
        tab[i][0] = s[i] - '0';
        tab[i][1] = (11 - tab[i][0]) % 11;
        if(i % 2 == 0) push(i + roz, tab[i][0], tab[i][1]);
        else push(i + roz, tab[i][1], tab[i][0]);
    }
    while(q--)
    {
        char z;
        cin >> z;
        if(z == '=')
        {
            int a, b;
            cin >> a >> b;
            if(a % 2 == 0) push(a + roz, b - tab[a][0], (11 - b) % 11 - tab[a][1]);
            else push(a + roz, (11 - b) % 11 - tab[a][1], b - tab[a][0]);
            tab[a][0] = b;
            tab[a][1] = (11 - b) % 11;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if(b % 2 == 0) cout << czyt(a + roz, b + roz).first << "\n";
            else cout << czyt(a + roz, b + roz).second << "\n";
        }
    }
}
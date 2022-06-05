#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

int tab[r][2];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin>>s;
    for(int i = 0; i < n; i++)
    {
        tab[i][0] = s[i] - '0';
        tab[i][1] = (11 - tab[i][0]) % 11;
    }
    while(q--)
    {
        char z;
        cin >> z;
        if(z == '=')
        {
            int a, b;
            cin >> a >> b;
            tab[a][0] = b;
            tab[a][1] = (11 - b) % 11;
        }
        else
        {
            int a, b;
            cin >> a >> b;
            bool k = 0;
            int wyn = 0;
            for(int i = b; i >= a; i--)
            {
                wyn = (wyn + tab[i][k]) % 11;
                k = !k;
            }
            cout << wyn << "\n";
        }
    }
}
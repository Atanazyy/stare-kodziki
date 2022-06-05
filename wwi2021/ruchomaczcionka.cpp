#include <bits/stdc++.h>

using namespace std;

struct node {
    int syn[26];
};

const int r = 30000 * 20;

node tab[r];
bool czy[r];
string rek;

void dfs(int v, string slo)
{
    if(slo.size() >= 1) cout << slo[slo.size() - 1] << "\n" ;
    if(czy[v]) cout<<"P\n";
    int las = -1;
    for(int i = 0; i < 26; i++)
    {
        if(tab[v].syn[i] != 0) 
        {
            if(slo + (char)(i + 'a') == rek.substr(0, slo.size() + 1)) 
                las = i;
            else
            {
                dfs(tab[v].syn[i], slo + (char)(i + 'a'));
            }
        }
    }
    if(las != -1)
        dfs(tab[v].syn[las], slo + (char)(las + 'a'));
    if(slo != rek.substr(0, slo.size())) cout << "-\n";
}

int main()
{
    int n, mie = 1, ma = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ma = max(ma, (int)s.size());
        if(ma == (int)s.size())
            rek = s;
        int akt = 1;
        for(auto x : s)
        {
            if(tab[akt].syn[x - 'a'] == 0)
            {
                int pop = akt;
                akt = ++mie;
                tab[pop].syn[x - 'a'] = mie;
            }
            else
            {
                akt = tab[akt].syn[x - 'a'];
            }
        }
        czy[akt] = 1;
    }
    cout<<2 * (mie - 1) - ma + n << "\n";
    dfs(1, "");
}
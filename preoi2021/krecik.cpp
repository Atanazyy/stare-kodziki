#include <bits/stdc++.h>

using namespace std;

const int r = 3e5;
vector <int> G[r];
vector <int> T[r];
vector <int> S[r];
int wag[r];
int tab[r];
bool odw[r];
int nrs[r];
vector <int> kol;
stack <int> stos;
int sto[r];
int wyn[r];
int por = 1;

void uk(int v)
{
    odw[v] = 1;
    for(auto x : G[v])
    {
        if(!odw[x])
            uk(x);
    }
    kol.push_back(v);
}

void prz(int v)
{
    nrs[v] = por;
    for(auto x : T[v])
    {
        if(nrs[x] == 0)
            prz(x);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        T[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!odw[i]) uk(i);
    reverse(kol.begin(), kol.end());
    for(auto x : kol)
    {
        if(nrs[x] == 0) 
        {
            prz(x);
            por ++;
        }
    }
    for(int i = 1; i <= n; i++)
        wag[nrs[i]] += tab[i];
    for(int i = 1; i <= n; i++)
    {
        //cout << i << " " << nrs[i] << "\n";
        for(auto x : G[i])
        {
            if(nrs[i] != nrs[x])
            {
                S[nrs[i]].push_back(nrs[x]);
                sto[nrs[x]] ++;
            }
        }
    }
    por --;
    kol.clear();
    for(int i = 1; i <= por; i++)
    {
        if(sto[i] == 0) stos.push(i);
    }
    while(!stos.empty())
    {
        int v = stos.top();
        kol.push_back(v);
        stos.pop();
        for(auto x : S[v])
        {
            sto[x] --;
            if(sto[x] == 0) stos.push(x);
        }
    }
    int ow = 0;
    for(auto x : kol)
    {
        //cout << x << " ";
        wyn[x] += wag[x];
        ow = max(ow, wyn[x]);
        for(auto y : S[x])
        {
            wyn[y] = max(wyn[y], wyn[x]);
        }
    }
    cout << ow;
}
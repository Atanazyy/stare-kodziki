#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
bool odw[r];
vector <int> G1[r];
vector <int> G2[r];
vector <int> T1[r];
vector <int> post;
vector <int> kol;
vector <int> sor;
int sto[r];
int kto[r];
int wyn[r];
int roz[r];
int N;

void dfs1(int v)
{
    odw[v] = 1;
    for(auto u : G1[v])
    {
        if(!odw[u])
            dfs1(u);
    }
    post.push_back(v);
}

void dfs2(int v)
{
    kto[v] = N;
    roz[N] ++;
    for(auto u : T1[v])
    {
        if(kto[u] == 0)
            dfs2(u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G1[a].push_back(b);
        T1[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!odw[i]) 
            dfs1(i);
    reverse(post.begin(), post.end());
    for(auto v : post)
        if(kto[v] == 0) 
        {
            N++;
            dfs2(v);
        }
    for(int i = 1; i <= n; i++)
    {
        for(auto v : G1[i])
        {
            if(kto[i] != kto[v]) 
            {
                G2[kto[i]].push_back(kto[v]);
                sto[kto[v]]++;
            }
        }
    }
    for(int i = 1; i <= N; i++)
        if(sto[i] == 0)
            kol.push_back(i);
    while(!kol.empty())
    {
        int v = kol.back();
        sor.push_back(v);
        kol.pop_back();
        for(auto u : G2[v])
        {
            sto[u]--;
            if(sto[u] == 0)
                kol.push_back(u);
        }
    }
    reverse(sor.begin(), sor.end());
    for(auto v : sor)
    {
        for(auto u : G2[v])
            wyn[v] += roz[u] + wyn[u];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << wyn[kto[i]] + roz[kto[i]] - 1 << "\n";
    }
}
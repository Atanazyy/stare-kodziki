#include <bits/stdc++.h>

using namespace std;

vector<int> tab[50009];
vector<int> tra[50009];
vector <int> kol;
vector<int> sss[50009];
bool odw[50009];
int nr;
int spo[50009];
int roz[50009];
vector<int> top;

void dfs(int v)
{
    odw[v]=1;
    for(auto x:tab[v])
    {
        if(!odw[x])
            dfs(x);
    }
    kol.push_back(v);
}

void dfs2(int v)
{
    odw[v]=0;
    spo[v]=nr;
    for(auto x:tra[v])
    {
        if(odw[x])
            dfs2(x);
    }
}

void dfs3(int v)
{
    odw[v]=1;
    for(auto x:sss[v])
    {
        if(!odw[x])
            dfs3(x);
    }
    top.push_back(v);
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        tab[a].push_back(b);
        tra[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!odw[i])
            dfs(i);
    }
    reverse(kol.begin(),kol.end());
    nr=1;
    for(auto v:kol)
    {
       // cout<<v<<"\n";
        if(odw[v])
        {
            dfs2(v);
            nr++;
        }
    }
    nr--;
    /*for(int i=1;i<=n;i++)
    {
        cout<<i<<" "<<spo[i]<<"\n";
    }*/
    for(int v=1;v<=n;v++)
    {
        roz[spo[v]]++;
        for(int u:tab[v])
        {
            if(spo[v]!=spo[u])
            {
                sss[spo[v]].push_back(spo[u]);
            }
        }
    }
    /*for(int i=1;i<=nr;i++)
    {
        for(int u:sss[i])
        {
            cout<<i<<" "<<u<<"\n";
        }
    }*/
    for(int i=1;i<=nr;i++)
    {
        if(!odw[i])
            dfs3(i);
    }
    for(auto v:top)
    {
        for(auto u:sss[v])
        {
            roz[v]+=roz[u];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<roz[spo[i]]-1<<"\n";
    }

}
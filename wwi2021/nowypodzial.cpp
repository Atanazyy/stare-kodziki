#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
vector <int> tab[r];
int roz[r];
long long pod[r];
int k;
int w;

bool comp(int a, int b)
{
    return pod[a] > pod[b];
}

void dfs(int v, int o)
{
    pod[v] = roz[v];
    if(tab[v].size() == 1 && v != 1) 
    {
        return;
    }
    for(auto u : tab[v])
    {
        if(u == o) continue;
        dfs(u, v);
        pod[v] += pod[u];
    }
    sort(tab[v].begin(), tab[v].end(), comp);
     //cout<<pod[1]<<pod[2]<<" ";
    for(auto u : tab[v])
    {
        if(pod[v] <= k) break;
        if(u == o) continue;
        w++;
        pod[v] -= pod[u];
    }
    //cout<<v<<" "<<pod[v]<<"\n";
}
int main()
{
    int n;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> roz[i];
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    dfs(1, 0);
    cout << w + 1;
}
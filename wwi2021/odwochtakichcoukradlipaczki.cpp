#include <bits/stdc++.h>

using namespace std;

struct kra
{
    int a;
    int b;
    int c;
};

const int r = 1e6 + 9;
vector <int> tab[r];
int las[r];
kra edg[r];
vector <int> cyk;
bool odw[r];
long long pre[r];

void dfs(int v, int e)
{
    while(las[v] < tab[v].size())
    {
        int i = tab[v][las[v]];
        auto k = edg[i];
        int u = k.b;
        las[v]++;
        if(k.b == v) u = k.a;
        if(!odw[i])
        {
            odw[i] = 1;
            dfs(u, i);
        }
    }
    if(e != -1) cyk.push_back(e);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    int n, m;
    long long sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i] = {a, b, c};
        tab[a].push_back(i);
        tab[b].push_back(i);
        sum += c;
    }
    for(int i = 1; i <= n; i++)
    {
        if(tab[i].size() != 0)
        {
            dfs(i, -1);
            break;
        }
    }
    if(cyk.size() < m || sum < 0)
    {
        cout<<"LEPIEJ_POROBIC_MEMY";
        return 0;
    }
    cout << "PRZYGODA\n";
    pre[0] = edg[cyk[0]].c;
    long long mi = pre[0];
    int ind = 0;
    for(int i = 1; i < m; i++)
    {
        pre[i] = pre[i - 1] + edg[cyk[i]].c;
        if(pre[i] < mi)
        {
            mi = pre[i];
            ind = i;
        }
    }
    for(int i = 0; i < m; i++)
    {
        ind = (ind + 1) % m;
        cout << cyk[ind] << " ";
    }
}
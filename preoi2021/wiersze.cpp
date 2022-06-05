#include <bits/stdc++.h>

using namespace std;

const int r = 1e3 + 9;
int in[r];
int out[r];
vector<int> ns[r];
vector <int> G[r];
int odw[r];
bool wie[r];
vector <int> spo;
vector<int> slo;
int start[r];

void dfs(int v)
{
    odw[v] = 1;
    spo.push_back(v);
    for(auto x : ns[v])
    {
        if(!odw[x])
            dfs(x);
    }
}

void eul(int v)
{
    while(G[v].size() > 0)
    {
        int u = G[v].back();
        G[v].pop_back();
        eul(u);
    }
    slo.push_back(v);
}

int solve()
{
    vector <int> pos;
    vector <int> neg;
    int wyn = 0;
    for(auto x : spo)
    {
        wyn += out[x];
        if(out[x] - in[x] > 0)
            for(int i = 0; i < out[x] - in[x]; i++)
                pos.push_back(x);
        if(out[x] - in[x] < 0)
            for(int i = 0; i < in[x] - out[x]; i++)
                neg.push_back(x);
    }
    if(pos.size() == 0)
    {
        eul(spo[0]);
        return 1 + wyn;
    }
    int roz = pos.size();
    while(pos.size() > 1)
    {
        int a = neg.back();
        int b = pos.back();
        G[a].push_back(b);
        neg.pop_back();
        pos.pop_back();
    }
    eul(pos[0]);
    return roz + wyn;
}

int main()
{
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        in[b] ++;
        out[a] ++;
        G[a].push_back(b);
        ns[b].push_back(a);
        ns[a].push_back(b);
        wie[a] = 1;
        wie[b] = 1;
    }
    for(int i = 1; i <= 1000; i++)
    {
        if(wie[i] && !odw[i])
        {
            dfs(i);
            res += solve();
            spo.clear();
        }
    }
    cout << slo.size() << "\n";
    reverse(slo.begin(), slo.end());
    for(auto x : slo)
        cout << x << " ";
}
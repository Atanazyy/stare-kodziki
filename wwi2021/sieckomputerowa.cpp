#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;

vector<pair<int,int> > tab[r];
int low[r];
int pre[r];
bool odw[r];
bool odd[r];
int num[r];
int wie[r];
vector<int> drz[r];
int p;
int nr;

int DFS(int x, int pop) 
{
    if (low[x] != 0) 
        return pre[x];
    low[x] = pre[x] = ++p; 
    for (auto v : tab[x])
    {
        if (v.second != pop)
            low[x] = min(low[x], DFS(v.first, v.second));
    }
    return low[x];
}

bool czy(int a, int b) 
{
    if (pre[a] > pre[b])
        swap(a, b);
    return low[b] > pre[a];
}

void bud(int x)
{
    odw[x] = 1;
    num[x] = nr;
    wie[nr] = x;
    for(auto v : tab[x])
    {
        if(!odw[v.first])
        {
            if(czy(x, v.first)) continue;
            bud(v.first);
        }
    }
    for(auto v : tab[x])
    {
        if(!odw[v.first])
        {
            if(!czy(x, v.first)) continue;
            nr ++;
            bud(v.first);
        }
    }
}

int wyn;
int v1, v2;

pair<int, int> szu(int x)
{
    odd[x] = 1;
    int r = 0, w = x;
    for(auto v : drz[x])
    {
        if(odd[v]) continue;
        pair<int, int> akt = szu(v);
        if(akt.first > r) 
        {
            r = akt.first;
            w = akt.second;
        }
    }
    return {r+1,w};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back({b, i});
        tab[b].push_back({a, i});
    }
    DFS(1, 0);
    nr = 1;
    bud(1);
    /*for(int i = 1; i <=n; i++)
        cout<<i<<" "<<num[i]<<"\n";*/
    for(int i = 1; i <=n; i++)
    {
        for(auto y:tab[i])
        {
            drz[num[i]].push_back(num[y.first]);
            drz[num[y.first]].push_back(num[i]);
            //cout << num[i] << " " << num[y.first]<<"\n";
        }
    }
    v1 = szu(1).second;
    for(int i = 1; i <=n; i++) odd[i] = 0;
    v2 = szu(v1).second;
    if(wie[v1] == wie[v2]) cout<<"1 2";
    else cout << wie[v1] << " " << wie[v2];
}
#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
int gdzie[r];
int co[r];
vector <int> G[r];
int gle[r];
int lcanext[r][25];
vector<int> wie;

void dfs(int v)
{
    for(auto x : G[v])
    {
        gle[x] = gle[v] + 1;
        dfs(x);
    }
}

int lca(int a, int b)
{
    //cout << a << " " << b << " ";
    if(gle[a] > gle[b])
        swap(a, b);
    for(int i = 24; i >= 0; i--)
    {
        //cout << gle[lcanext[b][i]] << " ";
        if(gle[a] <= gle[lcanext[b][i]])
        {
            b = lcanext[b][i];
            //cout << i << " ";
        }
    }
    //cout << a << " " << b << " ";
    for(int i = 24; i >= 0; i--)
    {
        if(lcanext[a][i] != lcanext[b][i])
        {
            //cout << a << " " << b << " ";
            a = lcanext[a][i];
            b = lcanext[b][i];
        }
    }
    if(a == b)
    {
        //cout << a << "\n";
        return a;
    }
    //cout << lcanext[a][0] << "\n";
    return lcanext[a][0];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector< pair<int, int> > zap;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        int v;
        cin >> v;
        if(c == 'a')
        {
            G[gdzie[v]].push_back(i);
            gdzie[i] = i;
            lcanext[i][0] = gdzie[v];
            wie.push_back(i);
        }
        if(c == 'b')
        {
            gdzie[i] = lcanext[gdzie[v]][0];
            zap.push_back({-1, gdzie[v]});
        }
        if(c == 'c')
        {
            int w;
            cin >> w;
            gdzie[i] = gdzie[v];
            zap.push_back({gdzie[v], gdzie[w]});
        }
    }
    dfs(0);
    /*for(auto v : wie)
    {
        cout << v << ": ";
        for(auto x : G[v])
            cout << x << " ";
        cout << "\n";
    }*/
    /*for(auto x : wie)
    {
        cout << x << ": " << gle[x] << "\n";
    }*/
    for(int i = 1; i < 25; i++)
    {
        for(auto x : wie)
        {
            lcanext[x][i] = lcanext[lcanext[x][i - 1]][i - 1];
            //cout << lcanext[x][i] << " ";
        }
        //cout << "\n";
    }
    for(auto x : zap)
    {
        if(x.first == -1)
            cout << x.second << "\n";
        else
            cout << gle[lca(x.first, x.second)] << "\n";
    }
}

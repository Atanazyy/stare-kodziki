#include <bits/stdc++.h>

using namespace std;

mt19937 r;

const int mn = 25;

vector<int> G[mn + 1];
int tab[mn + 1][mn + 1];

int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

int n;

vector<int> rp()
{
    vector<int> vec;
    for(int i = 0; i < n; i++)
        vec.push_back(i);
    for(int i = 0; i < n; i++)
        swap(vec[rr(0, n - 1)], vec[rr(0, n - 1)]);
    return vec;
}

void dfs(int v, int s, set <int> odw)
{
    for(auto u : G[v])
    {
        if(odw.find(u) != odw.end()) 
            continue;
        set <int> ns = odw;
        ns.insert(u);
        dfs(u, s, ns);
        tab[s][u]++;
    }
}

bool czy()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            tab[i][j] = 0;
        }
        tab[i][i] = 1;
        set <int> odw;
        dfs(i, i, odw);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(tab[i][j] == 0 && tab[j][i] > 1)
            {
                //cout << i << j << "\n";
                return 1;
            }
        }
    }
    return 0;
}

set <pair<int, int> > byl;

int main() //do podzadan 1 2 5
{
    int seed;
    cin >> seed;
    r.seed(seed);
    n = rr(2, mn);
    int m = rr(1, 100);
    int mo = 0;
    while(m--)
    {
        int a = rr(1, n);
        int b = rr(1, n);
        G[a].push_back(b);
        mo++;
        if(czy() || a == b || byl.find({a, b}) != byl.end())
        {
            G[a].pop_back();
            mo--;
        }
        byl.insert({a, b});
        //for(int i = 1; i <= n; i++)
    //{
      //  for(auto v : G[i]) cout << i << " " << v << ", ";
    //}
    //cout << "\n";
    }
    cout << n << " " << mo << "\n";
    //G[4].push_back(1);
    //czy();
    for(int i = 1; i <= n; i++)
    {
        for(auto v : G[i]) cout << i << " " << v << "\n";
    }
}
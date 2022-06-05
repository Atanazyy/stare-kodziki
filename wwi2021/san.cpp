#include <bits/stdc++.h>

using namespace std;

const int r = 50;

int h[r];
long long p[r];
vector <int> tab[r];
int sto[r];
unordered_map <long long, long long> mapa[r];
queue <int> kol;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie();cout.tie();
    int n;
    long long k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> h[i] >> p[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i < j && h[i] <= h[j])
            {
                tab[i].push_back(j);
                sto[j]++;
                //cout << i << j;
            }
        }
    }
    long long wyn = 0;
    for(int i = 1; i <=n; i++)
    {
        mapa[i][min(k,p[i])] = 1;
        if(p[i] >= k) wyn++;
        if(sto[i] == 0) 
            kol.push(i);
    }
    while(!kol.empty())
    {
        int v = kol.front();
        kol.pop();
        vector<pair<long long, long long> > vec;
        for(auto x : mapa[v])
        {
           vec.push_back(x);
        }
        for(auto u : tab[v])
        {
            sto[u]--;
            for(auto x:vec)
            {
                if(k > x.first + p[u]) mapa[u][x.first + p[u]] += x.second;
                else 
                {
                    mapa[u][k] += x.second;
                    wyn += x.second;
                }
            }
            if(sto[u] == 0)
                kol.push(u);
        }
    }
    cout << wyn;
}
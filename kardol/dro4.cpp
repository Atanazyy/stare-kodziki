#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
vector <int> tab[r];
int sto[r];
int wyn[r];
queue <int> kol;
vector<int> sor;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back(b);
        sto[b]++;
    }
    for(int i = 1; i <= n; i++)
        if(sto[i] == 0) kol.push(i);

    while(!kol.empty())
    {
        int v = kol.front();
        sor.push_back(v);
        kol.pop();
        for(auto u : tab[v])
        {
            sto[u]--;
            if(sto[u] == 0) kol.push(u);
        }
    }
    reverse(sor.begin(), sor.end());
    for(auto v : sor)
    {
        for(auto u : tab[v])
            wyn[v] += 1 + wyn[u];
    }

    for(int i = 1; i <= n; i++)
    {
        cout << wyn[i] << "\n";
    }
}


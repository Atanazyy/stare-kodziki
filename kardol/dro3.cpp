#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
vector <int> tab[r];
int wyn[r];

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
    }
    for(int i = n; i >= 1; i--)
    {
        for(auto v : tab[i])
        {
            wyn[i] += 1 + wyn[v];
        }
    }
    for(int i = 1; i <= n; i++)
    {
        cout << wyn[i] << "\n";
    }
}

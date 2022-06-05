#include <bits/stdc++.h>

using namespace std;

bool tab[1509][1509];

priority_queue <pair<int, pair<int, int> > > kol[1509];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        tab[x][y] = 1;
    }
    long long wyn = 0;
    for(int i = 1; i <= n; i++)
    {
        int d = 0;
        for(int j = m; j >= 1; j--)
        {
            if(tab[i][j])
            {
                d = 0;
                while(!kol[j].empty())
                {
                    auto x = kol[j].top();
                    kol[j].pop();
                    wyn += (long long)(i - x.second.first) * (x.second.second - d) * x.first;
                }
                continue;
            }
            d++;
            int akt = 1;
            while(!kol[j].empty())
            {
                auto x = kol[j].top();
                if(x.first <= d) 
                    break;
                kol[j].pop();
                wyn += (long long)(i - x.second.first) * x.second.second * x.first;
                akt += x.second.second;
            }
            kol[j].push({d, {i, akt}});
        }
    }
    //cout << wyn << "\n";
    for(int j = 1; j <= m; j++)
    {
        while(!kol[j].empty())
        {
            auto x = kol[j].top();
            //cout << x.first << " " << x.second.first << " " << x.second.second << ", ";
            kol[j].pop();
            wyn += (long long)(n + 1 - x.second.first) * x.second.second * x.first;
        }
        //cout << "\n";
    }
    cout << wyn;
}
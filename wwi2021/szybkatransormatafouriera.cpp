#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;

vector <int> tab[r];
int stoa[r];
int stob[r];
int kto[r];
queue <int> kol[3];

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i ++)
            cin >> kto[i];
        for(int i = 0; i < m; i ++)
        {
            int a, b;
            cin >> a >> b;
            tab[a].push_back(b);
            stoa[b] ++;
            stob[b] ++;
        }
        for(int i = 1; i <= n; i ++)
        {
            if(stoa[i] == 0)
                kol[kto[i]].push(i);
        }
        int akt = 1;
        int wyn = 0;
        while(!kol[1].empty() || !kol[2].empty())
        {
            if(kol[akt].empty())
            {
                wyn ++;
                if(akt == 1) akt = 2;
                else akt = 1;
            }
            int nas = kol[akt].front();
            //cout << nas << " ";
            kol[akt].pop();
            for(auto x : tab[nas])
            {
                stoa[x]--;
                if(stoa[x] == 0) kol[kto[x]].push(x);
            }
        }
        int w2 = 0;
        akt = 2;
        for(int i = 1; i <= n; i ++)
        {
            if(stob[i] == 0)
                kol[kto[i]].push(i);
        }
        while(!kol[1].empty() || !kol[2].empty())
        {
            if(kol[akt].empty())
            {
                w2 ++;
                if(akt == 1) akt = 2;
                else akt = 1;
            }
            int nas = kol[akt].front();
            //cout << nas << " ";
            kol[akt].pop();
            for(auto x : tab[nas])
            {
                stob[x]--;
                if(stob[x] == 0) kol[kto[x]].push(x);
            }
        }
        cout << min(wyn, w2) <<"\n";
        for(int i = 0; i <= n; i++)
        {
            tab[i].clear();
            stoa[i] = 0;
            stob[i] = 0;
            kto[i] =0;
        }
    }
}
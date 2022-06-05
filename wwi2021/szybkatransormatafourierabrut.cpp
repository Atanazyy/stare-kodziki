#include <bits/stdc++.h>

using namespace std;

const int r = 11;
int kol[r];
int kto[r];
vector <pair<int, int> > spr;
vector <int> whi;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {    
        spr.clear();
        whi.clear();
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) 
        {
            whi.push_back(i);
            cin>>kto[i];
        }
        for(int i = 0; i < m; i++) 
        {
            int a, b;
            cin >> a >>b;
            spr.push_back({a,b});
        }
        int w = n;
        do
        {
            for(int i = 0; i < n; i++)
            {
                kol[whi[i]] = i;
            }
            //for(auto x:whi) cout<< x<<" ";
            //cout<<"\n";
            int f = 0;
            for(auto x : spr)
            {
                if(kol[x.first] > kol[x.second]) 
                {
                    f = 1;
                    break;
                }
            }
            if(f)
                continue;
            //for(auto x:whi) cout<< x<<" ";
            //cout<<"\n";
            int akt = kto[whi[0]];
            int wyn = 0;
            for(int i = 1; i < n; i++)
            {
                if(akt != kto[whi[i]]) 
                {
                    akt = kto[whi[i]];
                    wyn++;
                }
            }
            w = min(w, wyn);
        } while (next_permutation(whi.begin(), whi.end()));
        cout << w << "\n";
    }
}
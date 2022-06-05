#include <bits/stdc++.h>

using namespace std;

const int r = 1e7 + 9;
const int inf = 1e9;
int wyn[r];
int tab[r];
stack <pair<int, int> > kol;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    for(int i = 0; i < n; i++)
    {
        while(!kol.empty())
        {
            int a = kol.top().first;
            int x = kol.top().second;
            if(a >= tab[i]) 
                break;
            kol.pop();
            wyn[x] = i - x;
        }
        kol.push({tab[i], i});
    }
    while(!kol.empty())
    {
        wyn[kol.top().second] = inf;
        kol.pop();
    }
    for(int i = n; i >= 0; i--)
    {
        while(!kol.empty())
        {
            int a = kol.top().first;
            int x = kol.top().second;
            if(a >= tab[i]) 
                break;
            kol.pop();
            wyn[x] = min(wyn[x], x - i);
        }
        kol.push({tab[i], i});
    }
    while(!kol.empty())
    {
        wyn[kol.top().second] = min(wyn[kol.top().second], inf);
        kol.pop();
    }
    for(int i = 0; i < n; i++)
        if(wyn[i] == inf) cout <<"inf ";
        else cout << wyn[i] << " ";
}
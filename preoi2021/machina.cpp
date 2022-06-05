#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
vector<vector<int> > tab, wyn, ost;

int main()
{
    int n, m, k, l;
    cin >> n >> m >> k >> l;
    for(int i = 0; i < n; i++)
    {
        vector <int> V, W;
        for(int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            V.push_back(x);
            W.push_back(0);
        }
        tab.push_back(V);
        wyn.push_back(W);
        ost.push_back(W);
    }
    for(int i = 0; i < n; i++)
    {
        deque <int> kol;
        for(int j = 0; j < l; j++)
        {
            int x = tab[i][j];
            while(kol.size() > 0 && kol.back() > x)
                kol.pop_back();
            kol.push_back(x);
        }
        int start = 0;
        wyn[i][start] = kol.front();
        for(int j = l; j < m; j++)
        {
            int x = tab[i][j];
            while(kol.size() > 0 && kol.back() > x)
                kol.pop_back();
            kol.push_back(x);
            if(kol.front() == tab[i][start])
                kol.pop_front();
            start ++;
            wyn[i][start] = kol.front();
        }
    }

    for(int j = 0; j < m - l + 1; j++)
    {
        deque <int> kol;
        for(int i = 0; i < k; i++)
        {
            int x = wyn[i][j];
            while(kol.size() > 0 && kol.back() > x)
                kol.pop_back();
            kol.push_back(x);
        }
        int start = 0;
        ost[start][j] = kol.front();
        for(int i = k; i < n; i++)
        {
            int x = wyn[i][j];
            while(kol.size() > 0 && kol.back() > x)
                kol.pop_back();
            kol.push_back(x);
            if(kol.front() == wyn[start][j])
                kol.pop_front();
            start ++;
            ost[start][j] = kol.front();
        }
    }

    for(int i = 0; i < n - k + 1; i++)
    {
        for(int j = 0; j < m - l + 1; j++)
            cout << ost[i][j] << " ";
        cout << "\n";
    }
}
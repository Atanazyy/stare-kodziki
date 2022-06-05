#include <bits/stdc++.h>

using namespace std;

pair<int, int> wia[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e9;
int tab[1009][1009]; //0 - lit 1 - mur 2 - puste 
int tem[1009][1009];
int odw[1009][1009];
int odk[1009][1009];
int n;

int bfs(pair<int, int> start, pair<int, int> koniec)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            tem[i][j] = tab[i][j];
            odw[i][j] = inf;
        }
    queue <pair<int, int> > kol;
    kol.push(start);
    odw[start.first][start.second] = 0;
    while(!kol.empty())
    {
        pair<int, int> v = kol.front();
        kol.pop();
        for(auto x : wia)
        {
            if(tem[v.first + x.first][v.second + x.second] != 2 || odw[v.first + x.first][v.second + x.second] != inf)
            {
                odw[v.first + x.first][v.second + x.second] = min(odw[v.first][v.second] + 1, odw[v.first + x.first][v.second + x.second]);
                continue;
            }
            odw[v.first + x.first][v.second + x.second] = min(odw[v.first][v.second] + 1, odw[v.first + x.first][v.second + x.second]);
            kol.push({v.first + x.first, v.second + x.second});
        }
    }
    return odw[koniec.first][koniec.second];
}

int bfs2(pair<int, int> start, pair<int, int> koniec)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            tem[i][j] = tab[i][j];
            odk[i][j] = inf;
        }
    queue <pair<int, int> > kol;
    kol.push(koniec);
    odk[koniec.first][koniec.second] = 0;
    while(!kol.empty())
    {
        pair<int, int> v = kol.front();
        kol.pop();
        for(auto x : wia)
        {
            if(tem[v.first + x.first][v.second + x.second] != 2 || odk[v.first + x.first][v.second + x.second] != inf)
            {
                odk[v.first + x.first][v.second + x.second] = min(odk[v.first][v.second] + 1, odk[v.first + x.first][v.second + x.second]);
                continue;
            }
            odk[v.first + x.first][v.second + x.second] = min(odk[v.first][v.second] + 1, odk[v.first + x.first][v.second + x.second]);
            kol.push({v.first + x.first, v.second + x.second});
        }
    }
    return odk[start.first][start.second];
}

/*void wyp()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << tem[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}*/

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    pair <int, int> start;
    pair <int, int> koniec;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for(int j = 0; j < (int)s.size(); j++)
        {
            if(s[j] == '#') 
            {
                tab[i][j + 1] = 1;
                continue;
            }
            if(s[j] == 'X') 
            {
                tab[i][j + 1] = 0;
                continue;
            }
            tab[i][j + 1] = 2;
            if(s[j] == 'P') start = {i, j + 1};
            if(s[j] == 'K') koniec = {i, j + 1};
        }
    }
    if(n > 200)
    {
        int x = bfs(start, koniec);
        if(x == inf) cout << "NIE";
        else cout << x;
        return 0;
    }
    bfs(start, koniec);
    bfs2(start, koniec);
    int wyn = inf;
    for(int i = 1; i <= n; i++)
    { 
        for(int j = 1; j <= n; j++)
        {
            if(tab[i][j] == 0)
            {
                cout << inf << " ";
                continue;
            }
            int sr = odw[i][j];
            int k = i;
            while(tem[k][j] != 0)
            {
                sr = min(sr, abs(k - i) + odw[k][j]);
                k++;
            }
            k = i;
            while(tem[k][j] != 0)
            {
                sr = min(sr, abs(k - i) + odw[k][j]);
                k--;
            }
            k = j;
            while(tem[i][k] != 0)
            {
                sr = min(sr, abs(k - j) + odw[i][k]);
                k++;
            }
            k = j;
            while(tem[i][k] != 0)
            {
                sr = min(sr, abs(k - j) + odw[i][k]);
                k--;
            }
            cout  << sr << " ";
            int akt = sr - 1;
            k = i;
            while(tem[k][j] != 0)
            {
                akt = min(akt + 1, odw[k][j]);
                wyn = min(wyn, akt + odk[k][j]);
                k++;
            }
            akt = sr - 1;
            k = i;
            while(tem[k][j] != 0)
            {
                akt = min(akt + 1, odw[k][j]);
                wyn = min(wyn, akt + odk[k][j]);
                k--;
            }
            akt = sr - 1;
            k = j;
            while(tem[i][k] != 0)
            {
                akt = min(akt + 1, odw[i][k]);
                wyn = min(wyn, akt + odk[i][k]);
                k++;
            }
            akt = sr - 1;
            k = j;
            while(tem[i][k] != 0)
            {
                akt = min(akt + 1, odw[i][k]);
                wyn = min(wyn, akt + odk[i][k]);
                k--;
            }
        }
        cout << "\n";
    }
    if(wyn == inf)
    {
        cout << "NIE";
        return 0;
    }
    cout << wyn;
}
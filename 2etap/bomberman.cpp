#include <bits/stdc++.h>

using namespace std;

pair<int, int> wia[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e9;
int tab[69][69]; //0 - lit 1 - mur 2 - puste 
int tem[69][69];
int odw[69][69];
int n;

void cop()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
        {
            tem[i][j] = tab[i][j];
            odw[i][j] = inf;
        }
}

int bfs(pair<int, int> start, pair<int, int> koniec)
{
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
                continue;
            odw[v.first + x.first][v.second + x.second] = odw[v.first][v.second] + 1;
            kol.push({v.first + x.first, v.second + x.second});
        }
    }
    return odw[koniec.first][koniec.second];
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
    if(n > 50)
    {
        cop();
        cout << bfs(start, koniec);
        return 0;
    }
    int wyn = inf;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(tab[i][j] == 0)
                continue;
            cop();
            int k = i;
            while(tem[k][j] != 0)
            {
                tem[k][j] = 2;
                k++;
            }
            k = i;
            while(tem[k][j] != 0)
            {
                tem[k][j] = 2;
                k--;
            }
            k = j;
            while(tem[i][k] != 0)
            {
                tem[i][k] = 2;
                k++;
            }
            k = j;
            while(tem[i][k] != 0)
            {
                tem[i][k] = 2;
                k--;
            }
            wyn = min(wyn, bfs(start, koniec));
            //cout << i << " " << j << "\n";
            //wyp();
        }
    }
    if(wyn == inf) cout << "NIE";
    else cout << wyn;
}
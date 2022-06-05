#include <bits/stdc++.h>
using namespace std;

bool tab[6009][6009];
bool wyn[6009][6009];
string s[6009];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    pair<int, int> start;
    bool z = 0;
    cin >> n >>m;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i];
        for(int j = 1; j <= m; j++)
        {
            if(s[i][j - 1] == '#')
            {
                tab[i][j] = 1;
                if(!z)
                {
                    z = 1;
                    start = {i, j};
                }
            }
           // cout<<tab[i][j] <<" ";
        }
        //cout<<"\n";
    }
    int h = 1;
    //cout << '\n';
    //cout<<start.first<<" "<<start.second<<"\n";
    while (start.first + h - 1 <= n)
    {
        if(s[start.first + h - 1][start.second - 1] == '.') break;
        h++;
    }
    h--;
    if(h % 5 != 0)
    {
        cout << "Olimpiada Informatyczna";
        return 0;
    }
    int siz = h / 5;
    int sze = siz * 7 * 2 + siz * 5 + start.second - 1;
    if(sze > m)
    {
        cout << "Olimpiada Informatyczna";
        return 0;
    }
    //cout << sze;
    for(int i = start.first; i < start.first + siz * 5; i++)
        for(int j = start.second; j < start.second + siz; j++)
            wyn[i][j] = 1;
    for(int i = start.first; i < start.first + siz; i++)
        for(int j = start.second; j < start.second + siz * 5; j++)
            wyn[i][j] = 1;
    for(int i = start.first + siz * 2; i < start.first + siz * 3; i++)
        for(int j = start.second; j < start.second + siz * 4; j++)
            wyn[i][j] = 1;

    start.second += siz * 7;

    for(int i = start.first; i < start.first + siz * 5; i++)
        for(int j = start.second; j < start.second + siz; j++)
            wyn[i][j] = 1;
    for(int i = start.first; i < start.first + siz; i++)
        for(int j = start.second; j < start.second + siz * 5; j++)
            wyn[i][j] = 1;
    for(int i = start.first + siz * 2; i < start.first + siz * 3; i++)
        for(int j = start.second; j < start.second + siz * 4; j++)
            wyn[i][j] = 1;

    start.second += siz * 7;

    for(int i = start.first; i < start.first + siz; i++)
        for(int j = start.second; j < start.second + siz * 5; j++)
            wyn[i][j] = 1;
    for(int i = start.first; i < start.first + siz * 5; i++)
        for(int j = start.second + siz * 2; j < start.second + siz * 3; j++)
            wyn[i][j] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(tab[i][j] != wyn[i][j])
            {
                cout << "Olimpiada Informatyczna";
                return 0;
            }
        }
        //cout<<"\n";
    }
    cout<<"FFT";
}
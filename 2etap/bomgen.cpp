#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

char tab[59][59];

int main() 
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int n = rr(2, 50);
    cout << n << "\n";
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int x = rr(1, 100);
            if(x <= 50)
                tab[i][j] ='.';
            else if(x <= 60) 
                tab[i][j] = 'X';
            else
                tab[i][j] = '#';
        }
    }
    pair <int, int> start = {rr(1, n), rr(1, n)};
    pair<int, int> koniec  = {rr(1, n), rr(1, n)};
    while(koniec == start)
        koniec  = {rr(1, n), rr(1, n)};
    tab[start.first][start.second] = 'P';
    tab[koniec.first][koniec.second] = 'K';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << tab[i][j];
        cout << "\n";}
}
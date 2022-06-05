#include <bits/stdc++.h>

using namespace std;

string wzo[1000];
string mac[1000];

bool czy(int x, int y, int dx, int dy)
{
    for(int i = 0; i < dx; i++)
    {
        for(int j = 0; j < dy; j++)
        {
            if(wzo[i][j] != mac[i + x][j + y])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n, m, l, k;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> wzo[i];
    cin >> l >> k;
    for(int i = 0; i < l; i++)
        cin >> mac[i];
    vector <pair<int, int> > wyn;
    for(int i = 0; i <= l - n; i++)
    {
        for(int j = 0; j <= k - m ; j++)
        {
            if(czy(i, j, n, m))
                wyn.push_back({i, j});
        }
    }
    cout << wyn.size() << "\n";
    sort(wyn.begin(), wyn.end());
    for(auto x : wyn)
        cout << x.first + 1<< " " << x.second + 1<< "\n";
}
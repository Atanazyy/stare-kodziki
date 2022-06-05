#include <bits/stdc++.h>

using namespace std;

int te[1009];
int poc[1009];
int kon[1009];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
        {
            te[a] ++;
            continue;
        }
        poc[a]++;
        kon[b]++;
    }
    int wyn = 2 * n;
    for(int i = 1; i <= 1000; i++)
    {
        if(poc[i] == 0 && kon[i] == 0)
            wyn -= poc[i];
        else
            wyn -= min(poc[i], kon[i]) + te[i];
    }
    cout << wyn;
}
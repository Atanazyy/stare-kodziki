#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
long long tab[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    sort(tab, tab + n);
    int m;
    cin >> m;
    while(m--)
    {
        long long a;
        cin >> a;
        int p = 0, k = n;
        while(p < k)
        {
            int sr = (p + k)/2;
            if(tab[sr] < a)
                p = sr + 1;
            else
                k = sr;
        }
        int x = k;
        a++;
        p = 0, k = n;
        while(p < k)
        {
            int sr = (p + k)/2;
            if(tab[sr] < a)
                p = sr + 1;
            else
                k = sr;
        }
        cout << k - x << "\n";
    }
}
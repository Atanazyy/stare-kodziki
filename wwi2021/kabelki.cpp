#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
int tab[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        int d, b;
        cin >> d >>b;
        tab[i] = b - d;
    }
    sort(tab, tab + n);
    int i = 0;
    long long sum = 0;
    while(sum <= 0 && i < n)
    {
        sum += tab[i];
        i++;
    }
    if(sum <= 0)
        cout << i;
    else
        cout<< i - 1;
}
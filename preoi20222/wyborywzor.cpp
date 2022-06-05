#include <bits/stdc++.h>

using namespace std;

const int r = 1e4;
int a[r];
pair<int ,int> b[r];
int n, k;

long double lic(int p)
{
    set <int> byl;
    long double wyn = 0;
    long double wol = 1;
    for(int i = 0; i < p; i++)
    {
        wyn += b[i].first / wol;
        byl.insert(b[i].second);
        wol ++;
    }
    vector <int> vec;
    for(int i = 0; i < n; i++)
    {
        if(byl.find(i) == byl.end())
            vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < k - p; i++)
        wyn += vec[i] / wol;
    return wyn;
}

int main()
{
    int ile = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i].first;
        if(b[i].first == -1)
        {
            b[i].first = 1e9;
            ile++;
        }
        b[i].second = i;
    }
    sort(b, b + n);
    long double wyn = 1e9;
    for(int i = 0; i <= min(k, n - ile); i++)
    {
        wyn = min(wyn, lic(i));
    }
    cout << fixed << setprecision(5) << wyn;
}


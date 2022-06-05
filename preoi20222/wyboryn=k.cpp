#include <bits/stdc++.h>

using namespace std;

vector <int> rek, nie;
pair<int, int> tab[100];
int n, k;

long double lic()
{
    if(rek.size() > k)
        return 1e9;
    vector <int> kos;
    for(auto x : rek)
        kos.push_back(tab[x].second);
    sort(kos.begin(), kos.end());
    long double wol = 1;
    long double wyn = 0;
    for(auto x : kos)
    {
        wyn += x / wol;
        wol ++;
    }
    kos.clear();
    for(auto x : nie)
        kos.push_back(tab[x].first);
    sort(kos.begin(), kos.end());
    for(int i = 0; i < k - rek.size(); i++)
        wyn += kos[i] / wol;
    return wyn;
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> tab[i].first >> tab[i].second;
        rek.push_back(tab[i].first - tab[i].second)
    }
    long double wyn = 1e9;

    for(int i = 0; i < (1 << n); i++)
    {
        rek.clear();
        nie.clear();
        int a = i;
        for(int j = 0; j < n; j++)
        {
            if(a % 2 == 1 && tab[j].second != -1)
                rek.push_back(j);
            else
                nie.push_back(j);
            a /= 2;
        }
        wyn = min(wyn, lic());
    }
    cout << fixed << setprecision(5) << wyn;
}

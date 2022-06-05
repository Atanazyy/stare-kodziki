#include <bits/stdc++.h>

using namespace std;

vector <int> rek, nie;
pair<int, int> tab[100];
int n, k;
int a[1000];
pair<int ,int> b[1000];

struct S2
{
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

    void solve()
    {
        int ile = 0;
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
};

struct S1
{
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

    void solve()
    {
        for(int i = 0; i < n; i++)
        {
            cin >> tab[i].first >> tab[i].second;
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
};

int main()
{
    cin >> n >> k;
    if(n > 20)
    {
        S2 xd;
        xd.solve();
    }
    else
    {
        S1 xd;
        xd.solve();
    }
}

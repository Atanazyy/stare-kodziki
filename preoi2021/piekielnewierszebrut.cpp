#include <bits/stdc++.h>

using namespace std;

pair<int, int> tab[100];
vector <int> vec;
vector <int> slo;
vector <int> wyn;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 10 * n; i++)
        wyn.push_back(i);
    for(int i = 1; i <= n; i++)
    {
        vec.push_back(i);
        cin >> tab[i].first >> tab[i].second;
    }

    do
    {
        slo.push_back(tab[vec[0]].first);
        slo.push_back(tab[vec[0]].second);
        for(int i = 1; i < n; i++)
        {
            if(slo.back() == tab[vec[i]].first)
                slo.push_back(tab[vec[i]].second);
            else
            {
                slo.push_back(tab[vec[i]].first);
                slo.push_back(tab[vec[i]].second);
            }
        }
        if(slo.size() < wyn.size())
        {
            swap(slo, wyn);
        }
        slo.clear();
    } 
    while (next_permutation(vec.begin(), vec.end()));
    cout << wyn.size() << "\n";
    for(auto x: wyn)
        cout << x << " ";
}
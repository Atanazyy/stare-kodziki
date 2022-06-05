#include <bits/stdc++.h>

using namespace std;

vector <int> tab;
int n;
int w[10000];

void ile()
{
    int wyn = 0;
    vector <int> tes = tab;
    while (!is_sorted(tes.begin(), tes.end()))
    {
        wyn ++;
        for(int i = 0; i < n; i++)
        {
            if(tes[0] == tes[i] + 1 || (tes[0] == 1 && tes[i] == n))
            {
                vector <int> tem;
                tem.push_back(tes[i]);
                tem.push_back(tes[0]);
                for(int j = 1; j < n; j++)
                {
                    if(i != j) tem.push_back(tes[j]);
                }
                tes = tem;
                break;
            }
        }
    }
    if(wyn <= n - 1)
    {
        w[tab[0]]++;
    }
}

int main()
{
    long long wyn;
    cin >> n;
    for(int i = 1; i <= n; i++)
        tab.push_back(i);
    do
    {
        //for(auto x : tab) cout << x << " ";
        ile();
    }
    while(next_permutation(tab.begin(), tab.end()));
    int i = 1;
    while(w[i] != 0)
    {
        cout << i << " " << w[i] << "\n";
        i++;
    }
}
#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9;
vector <int> tab[200];
int P[r];

int bin(int w, int x)
{
    int p = 0,k = tab[w].size(), s;
    while(p < k)
    {
        s = (p + k) / 2;
        if(x < tab[w][s]) 
        {
            k = s;
        }
        else
        {
            p = s + 1;
        }
    }
    return p;
}

int main() 
{
    string s1, s2;
    cin >> s1 >> s2;
    s1 = '$' + s1;
    s2 = '$' + s2;
    P[0] = -1;
    int j = -1;
    for (int i = 1; i < s1.size(); i++)
    {
        while (j >= 0 && s1[j + 1] != s1[i])
        {
            j = P[j];
        }
        j++;
        P[i] = j;
    }
    int ost = 1;
    for(int i = 1; i < s1.size(); i++)
    {
        if(s2[ost] == s1[i])
        {
            ost++;
        }
        if(ost > s2.size()) 
        {
            cout << 0;
            return 0;
        }
    }
    string ns1 = "$", ns2 = "$";
    int l = 1;
    for(int i = P[s1.size() - 1] + 1; i < s1.size(); i++)
    {
        ns1 += s1[i];
        tab[s1[i]].push_back(l);
        l++;
    }
    for(int i = ost; i < s2.size(); i++)
    {
        ns2 += s2[i];
    }
    //cout << ns1 << " " << ns2;
    ost = 0;
    int wyn = 1;
    for(auto x : ns2)
    {
        if(x == '$') continue;
        if(tab[x].size() == 0)
        {
            cout << "INF";
            return 0;
        }
        int pom = bin(x, ost);
        if(pom == tab[x].size())
        {
            wyn++;
            ost = 0;
            pom = bin(x, ost);
        }
        ost = tab[x][pom];
        //cout << ost << " ";
    }
    cout << wyn;
}
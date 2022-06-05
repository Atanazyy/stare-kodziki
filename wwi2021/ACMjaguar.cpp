#include <bits/stdc++.h>
using namespace std;
struct v{
    int x;
    int y;
    int lp;
};
v pomA, tab[2007];
vector <v> xd, otoczka;
bool czy_wyp[2007];
int iw (v poc, v a, v b)
{
    a.x = a.x - poc.x;
    a.y = a.y - poc.y;
    b.x = b.x - poc.x;
    b.y = b.y - poc.y;
    return a.x * b.y - a.y * b.x;
}
bool acompare (v a, v b)
{
    if (iw(pomA,a,b) == 0)
    {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
    return iw(pomA,a,b) > 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    pomA.x = 1e9;
    pomA.y = 1e9;
    for (int i = 1;i <= n;i ++)
    {
        cin >> tab[i].x >> tab[i].y;
        tab[i].lp = i;
        if (tab[i].x == pomA.x && tab[i].y < pomA.y) pomA = tab[i];
        if (tab[i].x < pomA.x) pomA = tab[i];
    }
    for (int i = 1; i <= n;i ++)
    {
        if (tab[i].lp != pomA.lp) xd.push_back(tab[i]);
    }
    sort(xd.begin(),xd.end(),acompare);
    otoczka.push_back(pomA);
    otoczka.push_back(xd[0]);
    for (int i = 1;i < xd.size();i ++)
    {
        while (otoczka.size() >= 2 && iw(otoczka[otoczka.size()-2],otoczka[otoczka.size()-1],xd[i]) <= 0) otoczka.pop_back();
        otoczka.push_back(xd[i]);
    }
    for (int i = 0;i < otoczka.size() - 2;i ++) 
    {
        cout << otoczka[i].lp << ' ';
        
    }
    return 0;
}
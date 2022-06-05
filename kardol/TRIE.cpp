#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int tab[30];
    long long ile;
};

vector<Node> tre;

long long wyn = 0;

void dfs(int v, int byl)
{
    //cout << v << " " << tre[v].ile <<"\n";
    byl += tre[v].ile;
    wyn += byl * tre[v].ile;
    for(int i = 0; i < 30; i++)
    {
        if(tre[v].tab[i] != -1)
            dfs(tre[v].tab[i], byl);
    }
}

void wstaw(int v, int k, int n, string s)
{
    if(k == n) 
    {
        //cout << v << " ";
        tre[v].ile++;
        return;
    }
    if(tre[v].tab[s[k] - 'a'] != -1)
    {
        wstaw(tre[v].tab[s[k] - 'a'], k + 1, n, s);
        return;
    }
    tre[v].tab[s[k] - 'a'] = tre.size();
    Node nowy;
    nowy.ile = 0;
    for(int i = 0; i < 30; i++)
        nowy.tab[i] = - 1;
    tre.push_back(nowy);
    wstaw(tre[v].tab[s[k] - 'a'], k + 1, n, s);
}

int main()
{
    int n;
    cin >> n;
    Node nowy;
    nowy.ile = 0;
    for(int i = 0; i < 30; i++)
        nowy.tab[i] = - 1;
    tre.push_back(nowy);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        wstaw(0, 0, s.size(), s);
    }
    dfs(0, 0);
    /*for(int i = 0; i < tre.size(); i++)
    {
        cout << i << ": ";
        for(int j = 0; j < 3; j++)
            cout << tre[i].tab[j] << " ";
        cout << "\n";
    }*/
    cout << wyn;
}
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int tab[2];
    int l;
};

vector <Node> trie;
vector <int> lic;
int akt;

void dod(int v)
{
    if(lic.size() == 0)
    {
        trie[v].l = akt;
        return;
    }
    int ost = lic.back();
    lic.pop_back();
    if(trie[v].tab[ost] == -1)
    {
        trie[v].tab[ost] = trie.size();
        Node X;
        X.tab[0] = -1;
        X.tab[1] = -1;
        X.l = -1;
        trie.push_back(X);
    }
    dod(trie[v].tab[ost]);
}

int szuk(int v)
{
    if(lic.size() == 0)
        return trie[v].l ^ akt;
    int chc = !lic.back();
    lic.pop_back();
    if(trie[v].tab[chc] == -1)
        chc = !chc;
    return szuk(trie[v].tab[chc]);
}

int main()
{
    int n;
    cin >> n;
    int pre = 0;
    Node X;
    X.l = 0;
    X.tab[0] = -1;
    X.tab[1] = -1;
    trie.push_back(X);
    int wyn = 0;
    for(int j = 0; j < 32; j++)
        lic.push_back(0);
    dod(0);
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pre ^= x;
        int tym = pre;
        akt = tym;
        for(int j = 0; j < 32; j++)
        {
            lic.push_back(tym % 2);
            tym /= 2;
        }
        dod(0);
        tym = pre;
        for(int j = 0; j < 32; j++)
        {
            lic.push_back(tym % 2);
            tym /= 2;
        }
        int ter = szuk(0);
        //cout << ter << "\n";
        wyn = max(wyn, ter);
        lic.clear();
    }
    cout << wyn;
    /*for(int i = 0; i < trie.size(); i++)
    {
        cout << i << " " << trie[i].tab[0] << " " << trie[i].tab[1] << " " << trie[i].l << "\n";
    }*/
}
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int cze;
    int bia;
    bool gw;
};

struct daz
{
    bool typ;
    int p;
    int k;
};

const int r = 1e7;
int roz;
node tree[r];
daz wej[r];
set <int> ska;
map <int, int> mapa;

void zep(int v)
{
    if(tree[v].gw)
    {
        swap(tree[v].bia, tree[v].cze);
        tree[v].gw = 0;
        tree[v * 2].gw = !tree[v * 2].gw;
        tree[v * 2 + 1].gw = !tree[v * 2 + 1].gw;
    }
}

void ubdat(int a, int b, int v, int p, int k)
{
    zep(v);
    if(a > k|| b < p) 
        return;
    if(p >= a && k <= b)
    {
        tree[v].gw = !tree[v].gw;
        zep(v);
        return;
    }
    int sr = (p + k) / 2;
    ubdat(a, b, v * 2, p, sr);
    ubdat(a, b, v * 2 + 1, sr + 1, k);
    tree[v].cze = tree[v * 2].cze + tree[v * 2 + 1].cze;
    tree[v].bia = tree[v * 2].bia + tree[v * 2 + 1].bia;
    return;
}

int kuery(int a, int b, int v, int p, int k)
{
    zep(v);
    if(a > k || b < p) 
        return 0;
    if(p >= a && k <= b)
        return tree[v].bia;
    int sr = (p + k) / 2;
    return kuery(a, b, v * 2, p, sr) + kuery(a, b, v * 2 + 1, sr + 1, k);
}

int main()
{
    int n, q;
    cin >> n >> q;
    ska.insert(n);
    roz = ceil(log2(5 * q));
    roz = 1 << roz;
    for(int i = 0; i < q; i++)
    {
        char z;
        cin >> z;
        cin >> wej[i].p >> wej[i].k;
        ska.insert(wej[i].p);
        ska.insert(wej[i].k);
        if(z == '?') wej[i].typ = 1;
    }
    int v = 1;
    tree[v + roz - 1].bia = 1;
    mapa[1] = v;
    int ost = 1;
    v++;
    for(auto x : ska)
    {
        if(x > ost + 1) 
        {
            tree[v + roz - 1].bia = x - ost - 1;
            v++;
        }
        mapa[x] = v;
        tree[v + roz - 1].bia = 1;
        ost = x;
        v ++;
    }
    for(int i = roz - 1; i > 0; i--)
    {
        tree[i].bia = tree[i * 2].bia + tree[i * 2 + 1].bia;
    }
    //for(int i = 1; i < 2 * roz; i++) cout << tree[i].bia << " ";
    for(int i = 0; i < q; i++)
    {
        auto x = wej[i];
        if(x.typ)
            cout << kuery(mapa[x.p], mapa[x.k], 1, 1, roz) << "\n";
        else
            ubdat(mapa[x.p], mapa[x.k], 1, 1, roz);
    }
    return 0;
}
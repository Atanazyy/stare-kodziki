#include <bits/stdc++.h>

using namespace std;

struct node
{
    int cze;
    int bia;
    bool gw;
};

const int r = 1e7;
int roz;
node tree[r];

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
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
        tree[i + roz].bia = 1;
    for(int i = roz - 1; i > 0; i--)
        tree[i].bia = tree[i * 2].bia + tree[i * 2 + 1].bia;
    while(q--)
    {
        char z;
        cin >> z;
        if(z == '?')
        {
            int a, b;
            cin >> a >> b;
            cout << kuery(a, b, 1, 1, roz) << "\n";
        }
        else
        {
            int a, b;
            cin >> a >> b;
            ubdat(a, b, 1, 1, roz);
        }
    }
}
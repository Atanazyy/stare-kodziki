#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long sum;
    long long wyn;
    long long pre;
    long long suf;
};

const long long r = 1e6, z = 0;
long long roz;
node tree[r];

void push(long long v, long long x)
{
    tree[v].sum += x;
    tree[v].pre = max(tree[v].sum, z);
    tree[v].wyn = max(tree[v].sum, z);
    tree[v].suf = max(tree[v].sum, z);
    v /= 2;
    while(v > 0)
    {
        tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
        tree[v].pre = max(tree[v * 2].sum + tree[v * 2 + 1].pre, tree[v * 2].pre);
        tree[v].suf = max(tree[v * 2 + 1].sum + tree[v * 2].suf, tree[v * 2 + 1].suf);
        tree[v].wyn = max(max(tree[v * 2 + 1].wyn, tree[v * 2].wyn), tree[v * 2].suf + tree[v * 2 + 1].pre);
        v /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n, m, k, d;
    cin >> n >> m >> k >> d;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(long long i = roz; i < roz + n; i++)
        push(i, -k);
    while(m--)
    {
        long long v, x;
        cin >> v >> x;
        push(v + roz - 1, x);
        //for(long long i = 1; i < roz + roz; i++)
          //  cout << tree[v].wyn << " ";
        //cout << "\n";
        if(d * k >= tree[1].wyn)
            cout << "TAK\n";
        else
            cout << "NIE\n";
    }
}
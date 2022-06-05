#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long p;
    long long k;
    long long s;
};

const long long r = 1e6 + 9;
long long roz;
node tree[r];
string s;

void push(long long v)
{
    if(s[v] == 'P') 
    {
        tree[v + roz].p = 1;
        tree[v + roz].k = 0;
    }
    else 
    {
        tree[v + roz].k = 1;
        tree[v + roz].p = 0;
    }
    tree[v + roz].s = 0;
    v += roz;
    v /= 2;
    while(v > 0)
    {
        tree[v].p = tree[v * 2].p + tree[v * 2 + 1].p;
        tree[v].k = tree[v * 2].k + tree[v * 2 + 1].k;
        tree[v].s = tree[v * 2].s + tree[v * 2 + 1].s;
        tree[v].s += tree[v * 2].p * tree[v * 2 + 1].k;
        v /= 2;
    }
}

long long query(long long p, long long k)
{
    if(p == k) return 0;
    long long sump = tree[p].p;
    long long sumk = tree[k].k;
    long long wyn = tree[p].p * tree[k].k;
    while(p / 2 != k / 2)
    {
        if(p % 2 == 0)
        {
            wyn += tree[p + 1].s + tree[p + 1].p * sumk + tree[p + 1].k * sump;
            sump += tree[p + 1].p; 
        }
        if(k % 2 == 1)
        {
            wyn += tree[k - 1].s + tree[k - 1].p * sumk + tree[k - 1].k * sump;
            sumk += tree[k - 1].k; 
        }
        p /= 2;
        k/= 2;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, m;
    cin >> n >> m;
    roz = ceil(log2(n));
    roz = 1 << roz;
    cin >> s;
    for(long long i = 0; i < n; i++)
        push(i);
    while(m--)
    {
        /*for(long long i = 1; i < 2 * roz; i++)
        {
            cout << i << " " << tree[i].p << " " << tree[i].k << " " << tree[i].s << "\n"; 
        }*/
        char z;
        cin >> z;
        if(z == '?')
        {
            long long p, k;
            cin >> p >> k;
            cout << query(p + roz - 1, k + roz - 1) << "\n";
        }
        else
        {
            long long x;
            cin >> x;
            if(s[x - 1] == 'P') s[x - 1] = 'K';
            else s[x - 1] = 'P';
            push(x - 1);
        }
    }
}

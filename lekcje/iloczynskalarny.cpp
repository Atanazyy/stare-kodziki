#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long gwa;
    long long gwb;
    long long ilo;
    long long suma;
    long long sumb;
};

const long long r = 1e6;
node tree[r];
long long roz;

void zep(long long v, long long d)
{
    tree[v].ilo += tree[v].gwa * tree[v].gwb * d + tree[v].suma * tree[v].gwb + tree[v].sumb * tree[v].gwa;
    tree[v].suma += d * tree[v].gwa;
    tree[v].sumb += d * tree[v].gwb;
    tree[v * 2].gwa += tree[v].gwa;
    tree[v * 2].gwb += tree[v].gwb;
    tree[v * 2 + 1].gwa += tree[v].gwa;
    tree[v * 2 + 1].gwb += tree[v].gwb;
    tree[v].gwa = 0;
    tree[v].gwb = 0;
}

long long zap(long long a, long long b, long long v, long long p, long long k, long long d)
{
    zep(v, d);
    if(a > k || b < p)
    {
        return 0;
    }
    if(p >= a && k <= b)
    {
        return tree[v].ilo;
    }
    long long sr = (p + k) / 2;
    return zap(a, b, v * 2, p, sr, d / 2)+ zap(a, b, v * 2 + 1, sr + 1, k, d / 2);
}

void akta(long long a, long long b, long long v, long long p, long long k, long long x, long long d)
{
    zep(v, d);
    if(a > k || b < p)
    {
        return;
    }
    if(p >= a && k <= b)
    {
        tree[v].gwa = x;
        zep(v, d);
        return;
    }
    long long sr = (p + k) / 2;
    akta(a, b, v * 2, p, sr, x, d / 2);
    akta(a, b, v * 2 + 1, sr + 1, k, x, d / 2);
    tree[v].ilo = tree[v * 2].ilo + tree[v * 2 + 1].ilo;
    tree[v].suma = tree[v * 2].suma + tree[v * 2 + 1].suma;
    tree[v].sumb = tree[v * 2].sumb + tree[v * 2 + 1].sumb;
}

void aktb(long long a, long long b, long long v, long long p, long long k, long long x, long long d)
{
    zep(v, d);
    if(a > k || b < p)
    {
        return;
    }
    if(p >= a && k <= b)
    {
        tree[v].gwb = x;
        zep(v, d);
        return;
    }
    long long sr = (p + k) / 2;
    aktb(a, b, v * 2, p, sr, x, d / 2);
    aktb(a, b, v * 2 + 1, sr + 1, k, x, d / 2);
    tree[v].ilo = tree[v * 2].ilo + tree[v * 2 + 1].ilo;
    tree[v].suma = tree[v * 2].suma + tree[v * 2 + 1].suma;
    tree[v].sumb = tree[v * 2].sumb + tree[v * 2 + 1].sumb;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    long long n, q;
    cin >> n >> q;
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        tree[roz + i].suma = x;
    }
    for(long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        tree[roz + i].sumb = x;
    }
    for(long long i = roz; i < 2 * roz; i++) tree[i].ilo = tree[i].suma * tree[i].sumb;
    for(long long v = roz - 1; v > 0; v--)
    {
        tree[v].ilo = tree[v * 2].ilo + tree[v * 2 + 1].ilo;
        tree[v].suma = tree[v * 2].suma + tree[v * 2 + 1].suma;
        tree[v].sumb = tree[v * 2].sumb + tree[v * 2 + 1].sumb;
    }
    while(q--)
    {
        char z;
        cin >> z;
        if(z == '?')
        {
            long long a, b;
            cin >> a >> b;
            cout << zap(a, b, 1, 1, roz, roz) << "\n";
        }
        else
        {
            char c;
            cin >> c;
            long long a, b, x;
            cin >> a >> b >> x;
            if(c == 'a') akta(a, b, 1, 1, roz, x, roz);
            else aktb(a, b, 1, 1, roz, x, roz);
        }
    }
}
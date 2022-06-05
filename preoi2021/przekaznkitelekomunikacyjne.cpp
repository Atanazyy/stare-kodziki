#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long sum;
    long long zeps;
    long long zepw;
};
const int r = 5e6;
pair<int, int> tab[r];
node tree[r];
int roz;

void zep(int v, int d)
{
    tree[v].sum += d * (2 * tree[v].zeps + (d - 1) * tree[v].zepw) / 2;
    tree[v * 2].zeps += tree[v].zeps;
    tree[v * 2].zepw += tree[v].zepw;
    tree[v * 2 + 1].zeps += tree[v].zeps + (d / 2) * tree[v].zepw;
    tree[v * 2 + 1].zepw += tree[v].zepw;
    tree[v].zeps = 0;
    tree[v].zepw = 0;
}

void ubdat(int a, int b, int v, int p, int k, int s, int w, int d)
{
    //cout << p << " " << k << " " << s << " " << w << "\n";
    zep(v, d);
    if(a > k || b < p)
        return;
    if(a <= p && k <= b)
    {
        tree[v].zeps += s;
        tree[v].zepw += w;
        zep(v, d);
        return;
    }
    int sr = (p + k) / 2;
    ubdat(a, b, v * 2, p, sr, s, w, d / 2);
    if(a > sr) ubdat(a, b, v * 2 + 1, sr + 1, k, s, w, d / 2);
    else ubdat(a, b, v * 2 + 1, sr + 1, k, s + w * (sr + 1 - max(a, p)), w, d / 2);
    tree[v].sum = tree[v * 2].sum + tree[v * 2 + 1].sum;
}

long long kuery(int a, int b, int v, int p, int k, int d)
{
    zep(v, d);
    if(a > k || b < p)
        return 0;
    if(p >= a && k <= b)
    {
        return tree[v].sum;
    }
    int sr = (p + k) / 2;
    return kuery(a, b, v * 2, p, sr, d / 2) + kuery(a, b, v * 2 + 1, sr + 1, k, d / 2);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q;
    cin >> n >> q;
    roz = ceil(log2(n));
    roz = 1 << roz;
    while(q--)
    {
       /* for(int i = 1; i < 2 * roz; i++)
            cout <<"{ " << tree[i].sum << " " << tree[i].zeps << " " << tree[i].zepw << "} ";
        cout <<"\n";*/
        char z;
        cin >> z;
        if(z == 'P')
        {
            int x, s, a;
            cin >> x >> s >> a;
            tab[x] = {s, a};
            int poc = floor(s / a), war, kon;
            if((double)s / a == ceil(s / a)) poc = poc - 1;
            kon = x + poc;
            poc = x - poc;
            poc = max(poc, 1);
            kon = min(kon, n);
            war = s - a * (x - poc);
            ubdat(poc, x, 1, 1, roz, war, a, roz);
            ubdat(x, kon, 1, 1, roz, s, -a, roz);
            ubdat(x, x, 1, 1, roz, -s, 0, roz);

        }
        else if(z == 'U')
        {
            int x;
            cin >> x;
            int s = tab[x].first, a = tab[x].second;
            int poc = floor(s / a), war, kon;
            if((double)s / a == ceil(s / a)) poc = poc - 1;
            kon = x + poc;
            poc = x - poc;
            poc = max(poc, 1);
            kon = min(kon, n);
            war = s - a * (x - poc);
            ubdat(poc, x, 1, 1, roz, -war, -a, roz);
            ubdat(x, kon, 1, 1, roz, -s, a, roz);
            ubdat(x, x, 1, 1, roz, s, -a, roz);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            long long xd =  kuery(a, b, 1, 1, roz, roz) / (b - a + 1);
            cout << xd << "\n";
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
pair<int, int> tab[r];
int tree[r];

void ubdat(int a, int b, int s, int w)
{
    int ost = s;
    for(int i = a; i <= b; i ++)
    {
        tree[i] += ost;
        ost += w;
    }
}

int kuery (int a, int b)
{
    int sum = 0;
    for(int i = a; i <= b; i ++) sum += tree[i];
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, q;
    cin >> n >> q;
    while(q--)
    {
        char z;
        cin >> z;
        if(z == 'P')
        {
            int x, s, a;
            cin >> x >> s >> a;
            if(a == 0) cout << "xd";
            tab[x] = {s, a};
            int poc = floor(s / a), war, kon;
            if((double)s / a == ceil(s / a)) poc = poc - 1;
            kon = x + poc;
            poc = x - poc;
            poc = max(poc, 1);
            kon = min(kon, n);
            war = s - a * (x - poc);
            ubdat(poc, x, war, a);
            ubdat(x, kon, s, -a);
            ubdat(x, x, -s, a);

        }
        else if(z == 'U')
        {
            int x;
            cin >> x;
            int s = tab[x].first, a = tab[x].second;
            if(a == 0) cout << "xd";
            int poc = floor(s / a), war, kon;
            if((double)s / a == ceil(s / a)) poc = poc - 1;
            kon = x + poc;
            poc = x - poc;
            poc = max(poc, 1);
            kon = min(kon, n);
            war = s - a * (x - poc);
            ubdat(poc, x, -war, -a);
            ubdat(x, kon, -s, a);
            ubdat(x, x, s, -a);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if(b - a + 1 == 0) cout << "xd";
            int xd = kuery(a, b) / (b - a + 1);
            cout << xd<< "\n";
        }
    }
}
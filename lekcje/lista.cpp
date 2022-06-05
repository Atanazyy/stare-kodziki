#include <bits/stdc++.h>

using namespace std;

struct el
{
    int x;
    el *nas;
    el *pop;
};

const int r = 2e5 + 9;

el *tab[r];

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    el *pie = new el;
    el *ost = new el;
    int r = 0;
    int q;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        tab[i] = new el;
        char c;
        cin >> c;
        if(c == '>')
        {
            int w;
            cin >> w;
            el *akt = new el;
            akt -> x = w;
            tab[i] =  akt;
            r ++;
            if(r == 1)
            {
                pie = akt;
                ost = akt;
            }
            else
            {
                akt -> nas= pie;
                pie -> pop = akt;
                pie = akt;
            }
        }
        else if(c == '<')
        {
            r--;
            pie = pie -> nas; // <==> pie = (*pie).nas;
        }
        else if(c == '-')
        {
            int y;
            cin >> y;
            el *akt = tab[y];
            r--;
            // cerr << akt -> x << (akt -> nas) -> x << (akt -> pop) -> x;
            if(akt == ost)
                ost = akt -> pop;
            else if(akt == pie)
                pie = pie -> nas;
            else
            {
                (akt -> pop) -> nas = akt -> nas;
                (akt -> nas) -> pop = akt -> pop;
            }
        }
        else
        {
            int w, y;
            cin >> w >> y;
            el *akt = tab[y];
            el *now = new el;
            tab[i] = now;
            r ++;
            now -> x = w;
            now -> pop = akt;
            if(akt == ost)
                ost = now;
            else 
            {
                now -> nas = akt -> nas;
                (akt -> nas) -> pop = now;
            }
            akt -> nas = now;
        }
        /*
        int siz = r;
        el *poc = pie;
        while(siz--)
        {
            cerr << (poc -> x) << " ";
            poc = poc -> nas;
        }
        cerr <<'\n';
        */
    }
    /*for(int i = 1; i < q; i++)
    {
        cerr << (tab[i] -> x) <<" ";
    }*/
    while(r--)
    {
        cout << (pie -> x) << " ";
        pie = pie -> nas;
    }
}

#include <bits/stdc++.h>

using namespace std;

bool tab[1000009];
int P[1000009];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        bool f=1;
        int n;
        cin>>n;
        cin>>P[0];
        if(P[0]!=0) 
            f=0;
        tab[0]=1;
        string wyn="a";
        for(int i=1;i<n;i++)
        {
            cin>>P[i];
            if (!f)
                continue;
            if (P[i]==P[i-1]+1)
            {
                tab[i]=tab[P[i-1]];
                wyn+=wyn[P[i-1]];
                continue;
            }
            int ps = P[i-1];
            bool z = !tab[P[i-1]];
            while (tab[ps] != z && ps !=0 )
                ps = P[ps-1];
            if(ps==0)
            {
                if (z && P[i]!=1)
                {
                    cout<<"NIE\n";
                    f = 0;
                    continue;
                }
                if(!z && P[i]!=0)
                {
                    cout<<"NIE\n";
                    f = 0;
                    continue;
                }
                tab[i]=z;
                if(z)
                    wyn+="a";
                else
                    wyn+="b";
                continue;
            }
            if (ps+1!=P[i])
            {
                cout<<"NIE\n";
                f = 0;
                continue;
            }
            tab[i]=z;
            if(z)
                wyn+="a";
            else
                wyn+="b";
        }
        if(f)
        {
            cout<<"TAK\n";
            cout<<wyn<<"\n";
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

queue <int> tab;

int main()
{
    int n = 1093;
    for(int i = 0; i < n; i++)
    {
        tab.push(i);
    }
    int nr = n;
    while(tab.size() > 1)
    {
        int a = tab.front();
        tab.pop();
        int b = tab.front();
        tab.pop();
        tab.push(nr);
        if(tab.size() == 1)
        {
            cout<<"out[0] = "<<"z"<<a<<" + z"<<b; 
            return 0;
        }
        cout<<"z"<<nr<<" = ";
        if(a < n) cout<<"in["<<a<<"] + ";
        else cout<<"z"<<a<<" + ";
        if(b < n) cout<<"in["<<b<<"]\n";
        else cout<<"z"<<b<<"\n";
        nr++;
    }
}
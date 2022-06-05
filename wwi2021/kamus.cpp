#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>graf[100002];
int ktory[100002];
int ile[100002];
int ile2[100002];
queue<int>q[3];

int toposort(int start, int n, int o){
    for (int i = 1; i<=n; ++i){
//        if (ile[i]==0)
//            cout<<i<<endl;
//            q[ktory[i]].push(i);

        if (o==1){
            if (ile[i]==0){
                q[ktory[i]].push(i);
            }
        }else{
            if (ile2[i]==0){
                q[ktory[i]].push(i);
            }
        }

    }
    int wynik = 0;
    if (q[start].size()==0){
        return 20000000;
    }
    while (q[1].size()+q[2].size()){
        while (q[start].size()){
            int node = q[start].front();
            //cout<<node<<": ";
            q[start].pop();
            for (int next : graf[node]){
                //cout<<next<<' '<<ile[next]<<"   ";
                if (o==1){
                    --ile[next];
                    if (ile[next]==0){
                        //cout<<"EE";
                        q[ktory[next]].push(next);
                    }
                }else{
                    --ile2[next];
                    if (ile2[next]==0){
                        //cout<<"EE";
                        q[ktory[next]].push(next);
                    }
                }
            }
            //cout<<endl;
        }
        if (start==1){
            start = 2;
        }else{
            start = 1;
        }
        if (q[start].size()!=0){
            ++wynik;
        }
    }
    return wynik;
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while (T--){
        //cout<<T<<endl;
        int n, m;
        cin>>n>>m;
        for (int i = 0; i<=n; ++i){
            graf[i].clear();
            ktory[i] = 0;
            ile[i] = 0;
            ile2[i] = 0;
        }
        for (int i = 1; i<=n; ++i){
            cin>>ktory[i];
        }
        for (int i = 0; i<m; ++i){
            int pi, dr;
            cin>>pi>>dr;
            graf[pi].push_back(dr);
            ++ile[dr];
            ++ile2[dr];
        }
//        for (int i = 1; i<=n; ++i){
//            cout<<ile[i]<<' ';
//        }
//        cout<<endl;
//        for (int i = 1; i<=n; ++i){
//            cout<<ile2[i]<<' ';
//        }
//        cout<<endl;
        //cout<<"R";
        int pi = toposort(1, n, 1);
        //cout<<"P"<<endl;
        //cout<<pi<<endl;
        //cout<<endl;
        int dr = toposort(2, n, 2);

        //cout<<dr<<endl;
        cout<<min(pi, dr)<<endl;
    }
    return 0;
}

/*
1
5 4
1 2 2 2 1
1 4
4 5
3 5
2 3
*/

/*
1
5 6
1 2 1 2 1
1 2
1 3
2 4
3 4
2 5
3 5
*/

/*
1
7 8
1 2 1 2 1 2 2
1 2
1 3
2 4
3 4
2 5
3 5
6 7
7 3
*/
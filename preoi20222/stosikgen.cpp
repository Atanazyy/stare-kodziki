
#include <bits/stdc++.h>

using namespace std;

mt19937_64 r;
int siz[300000];

long long rand(long long a, long long b)
{
	assert(a<=b);
	return a+r()%(b-a+1);
}

int main(){
	int seed,a,b,mv,n,m,z;
	cin>>seed;
	r.seed(seed);
	n=rand(1,10);
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
        if (i==1){
            a=1;
        }else{
            a=rand(1,3);
        }
        if (a==1){
            b=rand(0,i-1);
            siz[i]=siz[b]+1;
            cout<<'a'<<" "<<b<<endl;
        }
        if (a==3){
        b=rand(0,i-1);
        while(siz[b]==0){
            b=rand(0,i-1);
        }
            cout<<'b'<<" "<<b<<endl;
            siz[i]=siz[b]-1;
        }
        if (a==2){
                b=rand(0,i-1);
            cout<<'c'<<" "<<b<<" "<<rand(0,i-1)<<endl;
            siz[i]=siz[b];
        }
	}
    }

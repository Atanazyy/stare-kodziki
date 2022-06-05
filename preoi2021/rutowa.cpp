#include <bits/stdc++.h>
const int N = 3e6 + 1;
long long heights[N];
bool check(long long &x, long long &n) {
    if(x < heights[n]) {
        return false;
        }
    for(long long i = 1; i < n; i++) {
            if(heights[i]*n >= x*i) {
                return false;
                }
        }
    return true;
    }
int main() {
    std::ios_base::sync_with_stdio(0);
    long long n;
    std::string s;
    std::cin>>n>>s;
    int add;
    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == 'D') {
            add = -1;
            } else {
                add = 1;
                }
            heights[i] = heights[i - 1] + add;
        }
    int l = -3e6;
    int r = 3e6;
    long long mid;
    while(l < r) {
        mid = ceil((l + r)/2);
        if(check(mid, n)) {
            r = mid;
            }
        else {
            l = mid + 1;
            }
        //std::cout<<l<<" "<<r<<"\n";
        }
    std::cout<<l - heights[n];
    }

#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int ask(int c, int d) {
    int res;
    cout<<"? "<<c<<" "<<d<<endl;
    cin>>res;
    return res;
}

void solve() {
    int a=0, b=0, curr=1<<29, big=ask(0, 0);
    while(curr) {
        int first=ask(a+curr, b), second=ask(a, b+curr);     
        if(first==second) {
            if(big==1) {
                a+=curr;
            } else {
                b+=curr;
            }
            big=first;
        } else if(first==-1) {
            a+=curr;
            b+=curr;
        }
        curr>>=1;
    }
    cout<<"! "<<a<<" "<<b<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


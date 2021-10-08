#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int a, b;
    cin>>a>>b;
    if(a==b) {
        a*=10;
        b=a+1;
        cout<<a<<" "<<b<<endl;
    } else if(b==a+1) {
        cout<<a<<" "<<b<<endl;  
    } else if(a==9 && b==1) {
        cout<<"99 100"<<endl;
    } else {
        cout<<-1<<endl;
    }
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


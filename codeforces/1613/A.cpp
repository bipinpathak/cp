#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int go(int n) {
    int curr=1;
    while(n>=curr) {
        curr*=10;
    }   
    curr/=10;
    return curr;
}

void solve() {
    int x1, p1, x2, p2;
    cin>>x1>>p1>>x2>>p2;
    int m=max(go(x1), go(x2));
    p1+=7;
    p2+=7;
    while(x1<m) {
        x1*=10;
        p1--;
    }
    while(x2<m) {
        x2*=10;
        p2--;
    }
    if(p1<p2) {
        cout<<"<";
    } else if(p1>p2) {
        cout<<">";
    } else if(x1>x2) {
        cout<<">";
    } else if(x1<x2) {
        cout<<"<";
    } else {
        cout<<"=";
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


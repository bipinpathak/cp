#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int x;
    cin>>x;
    for(int a=1; a<=x; a++) {
        for(int b=1; b<=x; b++) {
            if(a%b==0 && a*b>x && a/b<x) {
                cout<<a<<" "<<b<<endl;
                return;
            }
        }
    }
    cout<< -1 <<endl;
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


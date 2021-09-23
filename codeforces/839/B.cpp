#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(k);
    for(auto &i : a) {
        cin>>i;
    }
    int four=n, two=2*n, one=0, x;
    for(auto &i : a) {
        x=min(four, i/4);
        i-=4*x;
        four-=x;
    }
    for(auto &i : a) {
        x=min(two, i/2);
        i-=2*x;
        two-=x;
    }
    for(auto &i : a) {
        if(i>1 && four) {
            if(i==2) {
                one++;
            }
            four--;
            i=0;
        }
    }
    one+=two+2*four;
    for(auto &i : a) {
        one-=i;
    }
    string ans=one<0?"NO":"YES";
    cout<<ans<<endl;
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


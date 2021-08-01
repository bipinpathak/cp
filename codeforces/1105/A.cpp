#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    int t=0, ans=1e9;
    for(int i=1; i<=100; i++) {
        int offer=0;
        for(auto j : a) {
            if(abs(i-j)<=1) {
                continue;
            }
            if(j>i) {
                offer+=j-(i+1);
            } else {
                offer+=i-1-j;
            }
        }
        if(offer<=ans) {
            ans=offer;
            t=i;
        }
    }
    cout<<t<<" "<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


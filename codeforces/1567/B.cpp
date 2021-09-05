#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> prefix;

void pre() {
    int n=3e5, prev=0;
    for(int i=0; i<=n; i++) {
        prefix.push_back(i^prev);
        prev=prefix.back();
    }
}

void solve() {
    int a, b;
    cin>>a>>b;
    int currXor=prefix[a-1];
    int ans=a;
    if(currXor!=b) {
        ans++;
        int need=currXor^b;
        if(need==a) {
            ans++;
        }
    }
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
    auto start=clock();
    int t = 1;
    cin>>t;
    pre();
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


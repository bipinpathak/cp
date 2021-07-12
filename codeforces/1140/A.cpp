#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), done(n);
    for(auto &i : a) {
        cin>>i;
        i--;
    }
    int ans=0, start=0;
    while(1) {
        while(start<n && done[start]) {
            start++;
        }
        if(start==n) {
            break;
        }
        ans++;
        int end=a[start];
        while(start<=end) {
            done[start]=1;
            end=max(end, a[start]);
            start++;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


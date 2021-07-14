#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(2*n);
    int total=0;
    for(int i=0; i<2*n; i++) {
        cin>>a[i];
        if(a[i]==1) {
            total++;
        } else {
            total--;
        }
    }
    int ans=2*n, curr=0;
    map<int, int> last;
    last[0]=-1;
    for(int i=0; i<2*n; i++) {
        if(a[i]==1) {
            curr++;
        } else {
            curr--;
        }
        if(i>=n-1 && last.count(curr-total)) {
            ans=min(ans, i-last[curr-total]);
        }
        if(i<n) {
            last[curr]=i;
        }
    }
    if(total==0) {
        ans=0;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}


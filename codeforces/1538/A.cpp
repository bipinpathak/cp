#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int low=0, high=0;
    for(int i=0; i<n; i++) {
        cin>>a[i];
        if(a[i]>a[high]) {
            high=i;
        }
        if(a[i]<a[low]) {
            low=i;
        }
    }
    int ans=max(low, high)+1;
    ans=min(ans, n-min(low, high));
    if(high<low) {
        swap(high, low);
    }
    ans=min(ans, low+1+n-high);
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


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n+1), first(n+1, n+1), last(n+1, 0), freq(n+1);
    for(int i=1; i<=n; i++) {
        cin>>a[i];
        first[a[i]]=min(first[a[i]], i);
        last[a[i]]=max(last[a[i]], i);
        freq[a[i]]++;
    }
    vector<int> arranged(n+1), color(n+1);
    for(int i=1; i<=n; i++) {
        arranged[i]=arranged[i-1];
        color[i]=color[i-1];
        int offer=0;
        if(i==last[a[i]]) {
            offer=freq[a[i]]+arranged[first[a[i]]-1]; 
        }
        if(offer>arranged[i]) {
            color[i]=a[i];
            arranged[i]=offer;
        }
    }
    int ans=n-arranged[n];
    vector<int> seen(n+1);
    for(int i=n; i; i--) {
       int offer;
       seen[a[i]]++;
       offer=n-arranged[i-1]-seen[a[i]];
       ans=min(ans, offer);
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

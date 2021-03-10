#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    int ans=0;
    for(auto &i : a) {
        cin>>i;
        ans+=2*i;
    }
    if(m!=n || n==2) {
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
    for(int i=0; i<n; i++) {
        cout<<i+1<<" "<<((i+1)%n)+1<<endl;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> rem(m);
    while(n--) {
        int x;
        cin>>x;
        x%=m;
        rem[x]++;
    }
    int ans=0;
    if(rem[0]) {
        ans++;
    }
    for(int i=1; i<=m/2; i++) {
        int common=min(rem[i], rem[m-i]); 
        if(common) {
            ans++;
            rem[i]-=common+1;
            rem[m-i]-=common+1;
        }
        rem[i]=max(rem[i], 0);
        rem[m-i]=max(rem[m-i], 0);
        ans+=rem[i]+rem[m-i];
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
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}


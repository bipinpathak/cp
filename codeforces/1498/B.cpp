#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    ll w;
    cin>>n>>w;
    map<ll, int> count;
    while(n--) {
        ll x;
        cin>>x;
        count[x]++;
    }
    vector<vector<ll>> a;
    for(auto i: count) {
        a.push_back({i.first, i.second});
    }
    n=(int)a.size();
    int ans=0, index=n-1;
    while(index>=0) {
        ll left=w;
        int curr=index;
        while(curr>=0) {
            a[curr][1]--;
            left-=a[curr][0];
            while(curr>=0 && (a[curr][1]==0 || a[curr][0]>left)) {
                curr--;
            }
        }
        if(left<w) {
            ans++;
        }
        while(index>=0 && a[index][1]==0) {
            index--;
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
    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}


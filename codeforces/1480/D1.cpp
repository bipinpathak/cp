#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    set<int> active;
    active.insert(-1);
    active.insert(-2);
    int ans=0, last=-3;
    while(n--) {
        int x;
        cin>>x;
        if(last==x) {
            if(active.size()>1) {
                ans++;
                active.clear();
            }
        } else if(active.find(x)==active.end()) {
            ans++;
        } else {
            ans++;
            if(active.size()==2) {
                active.clear();
            }
        }
        active.insert(x);
        last=x;
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


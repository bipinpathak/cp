#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int m, k;
    cin>>m>>k;
    vector<int> dishes(k+1);
    for(int i=1; i<=k; i++) {
        cin>>dishes[i];
    }
    int slack=0, exhauseted=0, count=0;
    set<int> alive;
    for(int i=0; i<m-1; i++) {
        int given, disappointed;
        cin>>given>>disappointed;
        if(disappointed && !exhauseted) {
            exhauseted=1;
            count=slack;
        }
        if(given) {
            dishes[given]--;
        } else {
            slack++;
        }
        if(exhauseted) {
            alive.insert(given);
        }
    }
    string ans(k, 'N');
    int low=1e5;
    for(int i=1; i<=k && exhauseted; i++) {
        if(alive.find(i)==alive.end()) {
            if(dishes[i]<=count) {
                ans[i-1]='Y';
            }
            low=min(low, dishes[i]);
        }
    }
    if(exhauseted) {
        slack-=low;
    }
    for(int i=1; i<=k; i++) {
        if(ans[i-1]=='N' && dishes[i]<=slack) {
            ans[i-1]='Y';
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
    int t=1;
    cin>>t;
    while(t--) {
        cin.ignore();
        solve();
    }
    return 0;
}

